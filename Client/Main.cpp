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
			cout << "菜单:" << endl;
			cout << "1、开始阅读" << endl;
			cout << "2、下一页" << endl;
			cout << "3、上一页" << endl;
			cout << "4、退出" << endl;
			cout << "请输入选项:" << endl;
			cin >> ch;
			c.choice = to_string(ch);
			string data = c.C_VDataEncapsulation();
			string data1=c.LinkV("127.0.0.1", 8022, data);
			if (c.C_VDataDeEncapsulation(data1))//用KeyCV解封，确认得到TS就OK,完成认证
				return true;
			else
				cout << "error" << endl;
		}
	}
	else
	{
		cout << "认证失败";
	}
	return 0;
}