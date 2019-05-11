#pragma once
#include <string>
#include <ctime>
#include<WinSock2.h>
#pragma comment(lib,"WS2_32.lib")
using namespace std;

class TGSserver {
public:
	string IDC;
	string IDV;
	string ADC;
	string ts4;
	string ticketTGS;
	string Authenticator;
	string KeyCV;
	string c2tgs;
	string KeyCTGS = "01010202";
	string lifet = "3600";
	void GetKeyCV();
	//查找数据库，根据Client发来的VID得到Client与V的会话密钥。
	string GetTicketV();
	//封装加密生成Client与V验证所需要的TicketV。
	string TGS_CDataEncapsulation();
	//封装加密整合生成最终要发回Client的数据包。
	void TGS_CDataDeEncapsulation();
	//将Client发来的数据包进行解封装。
	string TGS_TS();
	//获取当前TS时间戳
	void TGS_ticket();
	//解封ticketTGS
	void TGS_authenticator();
	//解封autnenticatorc
	bool Is_TureClient();
};