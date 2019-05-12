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
<<<<<<< HEAD
	c.IDC = "0001";
	if (c.Authentication())
	{
		cout << "nice" << endl;
		char ccc = getchar();
	}

=======
	c.CAddr = ip;
	while (c.CAddr.length() < 15)
		c.CAddr += "X";
	c.IDC = "0001";
	if (c.Authentication()==true)
	{
		while (1)
		{

		}
	}
>>>>>>> 9d774a628642d890a1558950f92167abf5787abf
	return 0;
}