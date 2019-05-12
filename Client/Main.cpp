#include "Client.h"
#include<iostream>
#include <string>
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
	c.CAddr = ip;
	while (c.CAddr.length() < 15)
		c.CAddr += "X";
	c.IDC = "0001";
	c.choice = "0";
	if (c.Authentication()==true)
	{
		cout << "ok" << endl;
		int cho;
		string d1;
		//开始阅读
		c.bookname = "test";
		d1=c.LinkV("127.0.0.1", 8022, c.C_VDataEnRead(c.bookname));
		c.C_VDataDeEnRead(d1);
		cout << c.content << endl;
		//下一页
		d1 = c.LinkV("127.0.0.1", 8022, c.C_VDataEnNextPage());
		c.C_VDataDeEnRead(d1);
		cout << c.content << endl;
		//上一页
		d1 = c.LinkV("127.0.0.1", 8022, c.C_VDataEnPrePage());
		c.C_VDataDeEnRead(d1);
		cout << c.content << endl;
	}
	return 0;
}