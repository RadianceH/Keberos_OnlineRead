#pragma once
#pragma once
#include<string>
#include<WinSock2.h>
#include <ctime>
#include<Windows.h>
#include<winsock.h>
#include<mysql.h>
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"WS2_32.lib")
using namespace std;

class ASserver {
public:
	string IDC;
	string IDTGS;
	string TS1;
	string KeyCTGS;
	string ADC;
	string lifet = "3600";
	string ts2;
	string Keyc = "43969527";
	string c2as;//从client处收到的消息
	void GetKeyCTGS();
	//查找数据库，根据Client发来的TGSID得到Client与TGS的会话密钥
	string GetTicketTGS();
	//封装加密生成Client与TGS验证所需要的TicketTGS
	string AS_CDataEncapsulation();
	//封装加密整合生成最终要发回Client的数据包
	void AS_CDataDeEncapsulation();
	//将Client发来的数据包进行解封装。
	string AS_TS();
	//获取当前TS时间戳
};