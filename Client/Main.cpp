﻿#include "Client.h"
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
	c.IDC = "0001";
	if (c.Authentication())
	{
		cout << "nice" << endl;
		char ccc = getchar();
	}

	return 0;
}