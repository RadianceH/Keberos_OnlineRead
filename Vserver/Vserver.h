#pragma once
#include <string>
#include <ctime>
#include<WinSock2.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;

class Vserver {
public:
	string c2v;
	string IDC;
	string ADC;
	string KeyCV="11111111";
	string ts5;
	string bookname;
	string content;
	int page;
	string V_CDataEncapsulation();
	//对最终要发回Client的数据包进行封装加密。
	void V_CDataDeEncapsulation(string data);
	//将Client发来的数据包进行解封装。
	string V_CDataEnread();
	void V_CDataDeEnread(string data);
	bool getbook();
	bool Is_TrueClient(string data);
	int function(string data);
	int function2(string data);
	string V_TS();
	//获取当前TS时间戳
};