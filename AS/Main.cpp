#include"AS.h"
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

DWORD WINAPI ServerThread(LPVOID lpParameter) {
	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	int receByt = 0;
	char RecvBuf[1024];
	char SendBuf[1024];
	while (1) {
		receByt = recv(*ClientSocket, RecvBuf, sizeof(RecvBuf), 0);
		//buf[receByt]='\0';
		if (receByt > 0) {
			cout << "接收到的消息是：" << RecvBuf << "            来自客户端:" << *ClientSocket << endl;
			// cout<<receByt<<endl;
		}
		else
		{
			cout << "接收消息结束！" << endl;
			break;
		}
		memset(RecvBuf, 0, sizeof(RecvBuf));
		cout << "请输入要发送到客户端的信息：" << endl;
		gets_s(SendBuf);
		int k = 0;
		k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
		if (k < 0) {
			cout << "发送失败" << endl;
		}
		memset(SendBuf, 0, sizeof(SendBuf));
	}//while
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}


int main()
{
	ASserver AS;
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	ServerAddr.sin_port = htons(8000);
	int n;
	n = bind(ServerSocket, (LPSOCKADDR)&ServerSocket, sizeof(ServerAddr));
	if (n == SOCKET_ERROR) {
		cout << "端口绑定失败！" << endl;
		return;
	}
	else {
		cout << "端口绑定成功：" << 8000 << endl;
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
}