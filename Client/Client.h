#pragma once
#include<string>
#include<WinSock2.h>
#include <iostream>
#include <ctime>
using namespace std;

 class Client {
 public:
	 string IDC;
	 string CAddr;
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
	 void Authentication();
	 //Keberos认证函数，相继调用AS认证函数，TGS认证函数，应用服务器认证函数，以完成Keberos认证过程，进而保证Client客户端能够与服务器请求服务。
	 void LinkAS(string ASAddr, int ASPort);
	 //AS交互认证函数，通过套接字通信函数与AS建立socket通信，并通过相应的数据封装函数和数据解封函数完成与AS的数据验证交互。
	 void LinkTGS(string TGSAddr, int TGSPort);
	 //TGS交互认证函数，通过套接字通信函数与TGS建立socket通信，并通过相应的数据封装函数和数据解封函数完成与TGS的数据验证交互。
	 void LinkV(string VAddr, int VPort);
	 //应用服务器交互认证函数，通过套接字通信函数与V应用服务器建立socket通信, 并通过相应的并通过相应的数据封装函数和数据解封函数完成与客户服务器的数据验证交互。

    /*以下为具体功能函数*/
	bool login();
	bool readbook();
	bool nextpage();
	bool prepage();
	bool collect();
	bool exit();
 private:
	/*以下为封装相关函数*/
	 string C_ASDataEncapsulation(string IDTGS);
	 //AS通信数据封装函数，根据Client向AS所需发送的数据进行封装加密。
	 string C_ASDataDeEncapsulation();
	 //AS通信数据解封装函数，根据AS发来的数据包，进行解密拆分。
	 string C_TGSDataEncapsulation(string IDV, string TicketTGS);
	 //TGS通信数据封装函数，根据Client向TGS所需发送的数据进行封装加密。
	 string C_TGSDataDeEncapsulation();
	 //TGS通信数据解封装函数，根据TGS发来的数据包，进行解密拆分。
	 string C_VDataEncapsulation(string TicketV);
	 //客户服务器通信数据封装函数，根据Client向服务器所需发送的数据进行封装加密。
	 string C_VDataDeEncapsulation();
	 //客户服务器通信数据解封装函数，根据TGS发来的数据包，进行解密拆分。
	 string C_TS();
	 //获取当前TS时间戳
};