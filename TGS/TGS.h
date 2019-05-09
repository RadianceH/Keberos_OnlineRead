#pragma once
#include <string>
#include <ctime>
#include<WinSock2.h>
using namespace std;

class TGSserver {
public:
	string IDC;
	string IDV;
	string ADC;
	string ticketTGS;
	string Authenticator;
	string KeyCV;
	string c2tgs;
	const int lifet = 3600;
	TGSserver(int Port);
	//socket等待监听，可实现创建多线程为多client提供服务。
	void GetKeyCV();
	//查找数据库，根据Client发来的VID得到Client与V的会话密钥。
	TGSserver();
	//构造函数
	~TGSserver();
	//析构函数
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