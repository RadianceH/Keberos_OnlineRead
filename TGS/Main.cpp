#include"TGS.h"
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>

using namespace std;

DWORD WINAPI ServerThread(LPVOID lpParameter) {
	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	TGSserver t;
	int receByt = 0;
	char RecvBuf[1024];
	char SendBuf[1024];
	ofstream tgsfile("tgslog.txt", ios::app);
	receByt = recv(*ClientSocket, RecvBuf, sizeof(RecvBuf), 0);
	if (receByt > 0) {
		cout << "接收到的消息是：" << RecvBuf << "            来自客户端:" << *ClientSocket << endl;
	}
	//判断是否OK
	t.c2tgs = RecvBuf;
	t.TGS_CDataDeEncapsulation();//拆包得到Auth Ticket 同时把Auth和Ticket在这个函数再细分拆开，去得到IDC ADC IDV
	if (t.Is_TureClient())
	{
		t.GetKeyCV();//查数据库得到KeyCTGS
		strcpy_s(SendBuf, t.TGS_CDataEncapsulation().c_str());//封装并且赋值给char数组SendBuf
		memset(RecvBuf, 0, sizeof(RecvBuf));
		int k = 0;
		k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
		if (k < 0) {
			cout << "发送失败" << endl;
		   }
		if (tgsfile.is_open())
		{
			tgsfile << t.TGS_TS() << " 收到来自" << t.ADC << "认证请求        认证成功！\n";
			tgsfile.close();
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
		if (tgsfile.is_open())
		{
			tgsfile << t.TGS_TS() << " 收到来自" << t.ADC << "认证请求        认证失败！\n";
			tgsfile.close();
		}
		memset(SendBuf, 0, sizeof(SendBuf));
	}
		closesocket(*ClientSocket);
		free(ClientSocket);
		return 0;
}

int main()
{

	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	ServerAddr.sin_port = htons(8011);
	int n;
	n = bind(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	if (n == SOCKET_ERROR) {
		cout << "端口绑定失败！" << endl;
		cout << WSAGetLastError() << endl;
		return 0;
	}
	else {
		cout << "端口绑定成功：" << 8011 << endl;
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