#pragma once
#include <string>
#include <ctime>
#include<WinSock2.h>
#include"Rsa.h"
#pragma comment(lib,"WS2_32.lib")
using namespace std;

class Vserver {
public:
	string c2v;
	string IDC;
	string ADC;
	RSA rsa;
	string KeyCV="33784581";
	string ts5;
	string bookname;
	string content;
	const string signdata = "ZZReadOnline";
	string sign;
	int page;
	/*以下为具体功能函数*/
    bool readbook();
	//阅读功能函数。
	bool nextpage();
	//下一页功能函数。
	bool prepage();
	//上一页功能函数。
	bool collect();
	//收藏书籍函数
	void exit();
	//退出功能函数。
	string V_CDataEncapsulation();
	//对最终要发回Client的数据包进行封装加密。
	void V_CDataDeEncapsulation(string data);
	//将Client发来的数据包进行解封装。
	string V_CDataEnread();
	void V_CDataDeEnread();
	bool getbook();
	bool Is_TrueClient(string data);
	int function();
	string V_TS();
	void GetSign();
	//获取当前TS时间戳
};