#include "Client.h"
#include "des.h"
#include <ctime>
#include<iostream>
using namespace std;

Client::Client(string Addr)
{
	CAddr = Addr;
}

void Client::SocketLink(string SockAddr, int SockPort)
{
	const char *SAddr=SockAddr.c_str();
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN  ClientAddr;

	ClientAddr.sin_family = AF_INET;
	ClientAddr.sin_addr.S_un.S_addr = inet_addr(SAddr);
	ClientAddr.sin_port = htons(SockPort);

	int n = 0;
	n = connect(ClientSocket, (struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
	if (n == SOCKET_ERROR) {
		cout << "连接失败" << endl;
		return ;
	}
	cout << "连接成功！" << endl;
	return;
}

void Client::SendData(string info)
{
    char SendBuff[1024] ;
	strcpy_s(SendBuff, info.c_str());
	int n = 0;
	n = send(ClientSocket, SendBuff, sizeof(SendBuff), 0);
	if (n < 0) {
		cout << "发送失败" << endl;
	}
	else cout << "发送成功！" << endl;
}

string Client::RecvData()
{
	char RecvBuff[1024];
	string Recvdata;
	int n = 0;
	n = recv(ClientSocket, RecvBuff, sizeof(RecvBuff), 0);
	if (n > 0) {
		cout << "接收到来自服务器的消息为：" << RecvBuff << endl;
	    Recvdata = RecvBuff;
		return Recvdata;
	}
	else
	{
		cout << "未接受到消息" << endl;
		return Recvdata;
	}
}

void Client::ExitSocket()
{
	closesocket(ClientSocket);
	WSACleanup();
}

string Client::LinkAS(string ASAddr, int ASPort, string data)
{
	SocketLink(ASAddr, ASPort);
	SendData(data);
	string info=RecvData();
	ExitSocket();
	return info;
}

string Client::LinkTGS(string TGSAddr, int TGSPort,string data)
{
	SocketLink(TGSAddr, TGSPort);
	SendData(data);
	string info = RecvData();
	ExitSocket();
	return info;
}

string  Client::LinkV(string VAddr, int VPort,string data)
{
	SocketLink(VAddr, VPort);
	SendData(data);
	string info = RecvData();
	ExitSocket();
	return info;
}

bool Client::Authentication()
{
	string data = C_ASDataEncapsulation();  //C->AS数据包
	string data1;
	data1 = LinkAS("127.0.0.1", 8000, data);//发送数据包，并且接受返回AS->C数据包
	if (C_ASDataDeEncapsulation(data1))//用KeyCAS解封AS->C,判断Lifetime,提取赋值成员变量KeyCTGS,TicketTGS
	{
		data = C_TGSDataEncapsulation();//C->TGS数据包，用C_GetAuthenticator()生成Authenticator，TicketTGS现有成员变量;
		data1 = LinkTGS("127.0.0.1", 8111, data);//发送数据包，并且接受返回TGS->C数据包
		if(C_TGSDataDeEncapsulation(data1));//用KeyCTGS解封TGS->C,判断Lifetime,提取赋值成员变量KeyCV,TicketV
		{
			data = C_VDataEncapsulation();//C->V数据包，生成Authenticator，TicketV现有成员变量;
			data1 = LinkV("127.0.0.1", 8222, data);//发送数据包，并且接受返回V->C数据包
			if (C_VDataDeEncapsulation(data1))//用KeyCV解封，确认得到TS就OK,完成认证
				return true;
		}
	}
	return false;
}

//获取当前时间戳
string Client::C_TS()
{
	time_t now;
	struct tm pt;
	time(&now);
	localtime_s(&pt, &now);
	string ts;
	string year, mon, day, hour, min, sec;
	year = to_string(pt.tm_year - 100);
	if (year.length() == 1)
	{
		year = "0" + year;
	}
	mon = to_string(pt.tm_mon + 1);
	if (mon.length() == 1)
	{
		mon = "0" + mon;
	}
	day = to_string(pt.tm_mday);
	if (day.length() == 1)
	{
		day = "0" + day;
	}
	hour = to_string(pt.tm_hour);
	if (hour.length() == 1)
	{
		hour = "0" + hour;
	}
	min = to_string(pt.tm_min);
	if (min.length() == 1)
	{
		min = "0" + min;
	}
	sec = to_string(pt.tm_sec);
	if (sec.length() == 1)
	{
		sec = "0" + sec;
	}
	ts = year + mon + day + hour + min + sec;
	return ts;
}

//AS通信数据封装函数，根据Client向AS所需发送的数据进行封装加密 20位 格式:(IDC+IDTGS+TS1)
string Client::C_ASDataEncapsulation()
{
	string tgsid = "2001";
	//TGSid默认2001
	string C2AS = "";
	string ts1=C_TS();
	C2AS += IDC;
	C2AS += tgsid;
	C2AS += ts1;
	return C2AS;
}

//AS通信数据解封装函数，根据AS发来的数据包，进行解密拆分
bool Client::C_ASDataDeEncapsulation(string data)
{
	string a;
	string temp;
	for (int i = 0; i < 10; i++)
	{
		a.assign(data, 0 + 8 * i, 8);
		temp += jiemi(a, Keyc);
	}
	KeyCTGS.assign(temp,0,8);
	TicketTGS.assign(temp, 28, 48);
	cout << "解密KeyCTGS:" << KeyCTGS << "  TicketTGS:" << TicketTGS << endl;
	return true;
}

//TGS通信数据封装函数，根据Client向TGS所需发送的数据进行封装加密
string Client::C_TGSDataEncapsulation()
{
	string authenticatorc = "";
	string sf = "";
	string ts3 = C_TS();
	//32加密
	authenticatorc += IDC;
	authenticatorc += CAddr;
	authenticatorc += ts3;
	authenticatorc += "0";
	string a;
	string temp;
	for (int i = 0; i < 4; i++)
	{
		a.assign(authenticatorc, 0 + 8 * i, 8);
		temp += jiami(a, KeyCTGS);
	}
	sf += "1001";//唯一指定服务器id
	sf += TicketTGS;
	sf += temp;
	return sf;
}

//TGS通信数据解封装函数，根据TGS发来的数据包，进行解密拆分
bool Client::C_TGSDataDeEncapsulation(string data)
{
	string a;
	string temp;
	for (int i = 0; i < 9; i++)
	{
		a.assign(data, 0 + 8 * i, 8);
		temp += jiemi(a, KeyCTGS);
	}
	KeyCV.assign(temp,0,8);
	TicketV.assign(temp,24,48);
	return true;
}

//客户服务器通信数据封装函数，根据Client向服务器所需发送的数据进行封装加密
string Client::C_VDataEncapsulation()
{
	string au = C_GetAuthenticator();
	string c2v = "";
	c2v += TicketV;
	c2v += au;
	return c2v;
}

//客户服务器通信数据解封装函数，根据V发来的数据包，进行解密拆分
bool Client::C_VDataDeEncapsulation(string data)
{
	string ts5;
	ts5.assign(data,6,6);
	string ts50;
	ts50.assign(C_GetAuthenticator(),25,6);
	int t1;
	int t2;
	t1 = atoi(ts5.c_str());
	t2 = atoi(ts50.c_str());
	if (t1 - t2 == 1)
		return true;
	else
		return false;
}

string Client::C_GetAuthenticator()
{
	string c2v = "";
	string ts5 = C_TS();
	c2v += IDC;
	c2v += CAddr;
	c2v += ts5;
	c2v += "0";
	string a;
	string temp;
	for (int i = 0; i < 4; i++)
	{
		a.assign(c2v, 0 + 8 * i, 8);
		temp += jiami(a, KeyCV);
	}
	return temp;
}