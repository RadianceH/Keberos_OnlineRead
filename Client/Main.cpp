#include "Client.h"
#include<iostream>


using namespace std;

int main()
{
	WSADATA wsaData;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
	char hostname[256];
	ret = gethostname(hostname, sizeof(hostname));
	HOSTENT* host = gethostbyname(hostname);
	string ip = inet_ntoa(*(in_addr*)*host->h_addr_list);
	Client c(ip);
	c.SocketLink(ip,8000);
	//通过套接字连接AS

	c.IDC = "0001";
	string c2asdata;
	c2asdata = c.C_ASDataEncapsulation();
	c.SendData(c2asdata);
	string a;
	a=c.RecvData();
	c.ExitSocket();
	return 0;
}