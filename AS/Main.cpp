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
			cout << "���յ�����Ϣ�ǣ�" << RecvBuf << "            ���Կͻ���:" << *ClientSocket << endl;
			// cout<<receByt<<endl;
		}
		else
		{
			cout << "������Ϣ������" << endl;
			break;
		}
		memset(RecvBuf, 0, sizeof(RecvBuf));
		cout << "������Ҫ���͵��ͻ��˵���Ϣ��" << endl;
		gets_s(SendBuf);
		int k = 0;
		k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
		if (k < 0) {
			cout << "����ʧ��" << endl;
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
		cout << "�˿ڰ�ʧ�ܣ�" << endl;
		return;
	}
	else {
		cout << "�˿ڰ󶨳ɹ���" << 8000 << endl;
	}
	int l = listen(ServerSocket, 20);
	cout << "�����׼���������ȴ���������" << endl;
	while (1)
	{
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ServerSocket, 0, 0);
		cout << "һ���ͻ��������ӣ�socket�ǣ�" << *ClientSocket << endl;
		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}
}