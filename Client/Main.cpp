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
		
	c.CAddr = ip;
	while (c.CAddr.length() < 15)
		c.CAddr += "X";
	c.IDC = "0001";
	if (c.Authentication()==true)
	{
		cout << "认证成功";
		while (1)
		{
			int ch;
			string datab;
			string dataa;
			cout << "菜单:" << endl;
			cout << "1、开始阅读" << endl;
			cout << "2、下一页" << endl;
			cout << "3、上一页" << endl;
			cout << "4、退出" << endl;
			cout << "请输入选项:" << endl;
			cin >> ch;
			switch (ch)
			{
			case 1:
				c.choice = "1";
				datab = c.C_VDataEnRead();
				c.SendData(datab);
				dataa=c.RecvData();
				c.C_VDataDeEnRead(dataa);
				cout << "content:" << c.content << endl;
				break;
			case 2:
				c.choice = "2";
				datab = c.C_VDataEnRead();
				c.SendData(datab);
				dataa = c.RecvData();
				c.C_VDataDeEnRead(dataa);
				cout << "content:" << c.content << endl;
				c.choice = "2";
				break;
			case 3:
				c.choice = "3";
				datab = c.C_VDataEnRead();
				c.SendData(datab);
				dataa = c.RecvData();
				c.C_VDataDeEnRead(dataa);
				cout << "content:" << c.content << endl;
				c.choice = "3";
				break;
			case 4:
				c.ExitSocket();
				return 0;
			}
		}
	}
	else
	{
		c.ExitSocket();
		cout << "认证失败";
	}
	return 0;
}