#include"Vserver.h"
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#pragma comment(lib,"libmysql.lib")
using namespace std;

DWORD WINAPI ServerThread(LPVOID lpParameter) {
	SOCKET* ClientSocket = (SOCKET*)lpParameter;
	Vserver v;
	int receByt = 0;
	char RecvBuf[1024];
	char SendBuf[1024];
	ofstream vfile("vlog.txt", ios::app);
	while (1)
	{
		while (1)
		{
			receByt = recv(*ClientSocket, RecvBuf, sizeof(RecvBuf), 0);
			if (receByt > 0) 
			{
				cout << "接收到的消息是：" << RecvBuf << "            来自客户端:" << *ClientSocket << endl;
				break;
			}
		}
		v.c2v = RecvBuf;
		//判断是否OK
		int f = v.function(v.c2v);//拆头部功能码，根据功能码返回int，0表示认证，1表示开始阅读，2表示下一页（根据文档功能码返回）
		cout << "v.c2v:"<<v.c2v << endl;
		switch (f)
		{
		case 0:   //认证
		{
			v.V_CDataDeEncapsulation(v.c2v);
			if (v.Is_TrueClient(v.c2v)==true)
			{
				v.GetSign();
				strcpy_s(SendBuf, v.V_CDataEncapsulation().c_str());//封装并且赋值给char数组SendBuf
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				if (vfile.is_open())
				{
					vfile << v.V_TS() << " 收到来自" << v.ADC << "认证请求          认证成功！\n";
					vfile.close();
				}
				memset(SendBuf, 0, sizeof(SendBuf)); 
			}
			else
			{
				strcpy_s(SendBuf, "认证失败，ticket与IDC不对应！");
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				if (vfile.is_open())
				{
					vfile << v.V_TS() << " 收到来自" << v.ADC << "认证请求          认证失败！\n";
					vfile.close();
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			break;
		}
		case 1:
		{
			v.V_CDataDeEnread(v.c2v);//解包得到bookname
			v.page = 1;
			if (v.getbook())//查找数据库，根据bookname，page 对content进行赋值
			{
				strcpy_s(SendBuf, v.content.c_str());//将content封装
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			else
			{
				strcpy_s(SendBuf, "查无此书！");
				v.page--;
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			break;
		}
		case 2:
		{
			v.page++;
			if (v.getbook())
			{
				strcpy_s(SendBuf, v.content.c_str());
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			else
			{
				strcpy_s(SendBuf,"已经是最后一页了！");
				v.page--;
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			break;
		}
		case 3:
		{
			v.page--;
			if (v.getbook())
			{
				strcpy_s(SendBuf, v.content.c_str());
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			else
			{
				strcpy_s(SendBuf, "已经是第一页了！");
				v.page++;
				memset(RecvBuf, 0, sizeof(RecvBuf));
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				memset(SendBuf, 0, sizeof(SendBuf));
			}
			break;
		}
		case 4: //充值功能，考虑RSA
		{
			break;
		}
		case 5:
		{
			strcpy_s(SendBuf,"已退出！");
			memset(RecvBuf, 0, sizeof(RecvBuf));
			int k = 0;
			k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
			if (k < 0) {
				cout << "发送失败" << endl;
			}
			memset(SendBuf, 0, sizeof(SendBuf)); 
			closesocket(*ClientSocket);
			free(ClientSocket);
			return 0;
		}
		}
	}
}


int main()
{
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	ServerAddr.sin_port = htons(8022);
	int n;
	n = bind(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	if (n == SOCKET_ERROR) {
		cout << "端口绑定失败！" << endl;
		cout << WSAGetLastError() << endl;
		return 0;
	}
	else {
		cout << "端口绑定成功：" << 8022 << endl;
	}
	int l = listen(ServerSocket, 20);
	cout << "服务端准备就绪，等待连接请求" << endl;
	while (1)
	{
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ServerSocket, 0, 0);
		cout << "一个客户端已连接，socket是：" << *ClientSocket << endl;
		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}
	return 0;
}