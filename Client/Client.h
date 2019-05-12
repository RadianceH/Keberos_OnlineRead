#pragma once
#include<string>
#include<WinSock2.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;
 class Client {
 public:
	 string IDC;
	 string CAddr;
	 string KeyCAS;
	 string KeyCTGS;
	 string TicketTGS;
	 string KeyCV;
	 string TicketV;
	 string content;
	 string Keyc = "43969527";
	 SOCKET ClientSocket;
	 Client(string Addr);
	 //构造函数，new Client并对成员变量用户ID以及用户IP地址赋值。
	 void SocketLink(string SockAddr, int SockPort);
	 //套接字通信函数，根据IP端口发起socket连接。
	 void SendData(string info);
	 //通过已连接的套接字，发送数据
	 string RecvData();
	 //通过已连接的套接字，接收数据
	 void ExitSocket();
	 //断开已连接的套接字
	 bool Authentication();
	 //Keberos认证函数，相继调用AS认证函数，TGS认证函数，应用服务器认证函数，以完成Keberos认证过程，进而保证Client客户端能够与服务器请求服务。
	 string LinkAS(string ASAddr, int ASPort,string data);
	 //AS交互认证函数，通过套接字通信函数与AS建立socket通信，并通过相应的数据封装函数和数据解封函数完成与AS的数据验证交互。
	 string LinkTGS(string TGSAddr, int TGSPort,string data);
	 //TGS交互认证函数，通过套接字通信函数与TGS建立socket通信，并通过相应的数据封装函数和数据解封函数完成与TGS的数据验证交互。
	 string LinkV(string VAddr, int VPort,string data);
	 //应用服务器交互认证函数，通过套接字通信函数与V应用服务器建立socket通信, 并通过相应的并通过相应的数据封装函数和数据解封函数完成与客户服务器的数据验证交互。

    /*以下为具体功能函数*/
	bool login();
	bool readbook();
	bool nextpage();
	bool prepage();
	bool collect();
	bool exit();
 
	/*以下为封装相关函数*/
	 string C_ASDataEncapsulation();
	 //AS通信数据封装函数，根据Client向AS所需发送的数据进行封装加密。
	 bool C_ASDataDeEncapsulation(string data);
	 //AS通信数据解封装函数，根据AS发来的数据包，进行解密拆分。
	 string C_TGSDataEncapsulation();
	 //TGS通信数据封装函数，根据Client向TGS所需发送的数据进行封装加密。
	 bool C_TGSDataDeEncapsulation(string data);
	 //TGS通信数据解封装函数，根据TGS发来的数据包，进行解密拆分。
	 string C_VDataEncapsulation();
	 //客户服务器通信数据封装函数，根据Client向服务器所需发送的数据进行封装加密。
	 bool C_VDataDeEncapsulation(string data);
	 //客户服务器通信数据解封装函数，根据TGS发来的数据包，进行解密拆分。

	 string C_VDataEnRead();
	 bool C_VDataDeEnRead();

	 string C_VDataEnNextPage();
	 void C_VDataDeEnNextPage();

	 string C_VDataEnPrePage();
	 void C_VDataDeEnPrePage();

	 string C_VDataEnCollect();
	 void C_VDataDeEnCollect();
	 
	 string C_VDataEnExit();
	 void C_VDataDeEnExit();
	 string C_TS();
	 //获取当前TS时间戳
	 string C_GetAuthenticator();
};