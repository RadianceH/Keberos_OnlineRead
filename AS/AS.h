#pragma once
#include<string>
#include<WinSock2.h>
using namespace std;

class ASserver {
public:
	ASserver(int Port);
	//socket等待监听，可实现创建多线程为多client提供服务
	string GetKeyCTGS(string TGSID);
	//查找数据库，根据Client发来的TGSID得到Client与TGS的会话密钥
private:
	string GetTicketTGS(string KeyCTGS, string IDC, string CAddr, string IDTGS, int LifeTime2);
	//封装加密生成Client与TGS验证所需要的TicketTGS
	string AS_CDataEncapsulation(string TicketTGS, string KeyCTGS, string IDTGS, int LifeTime2);
	//封装加密整合生成最终要发回Client的数据包
	string AS_CDataDeEncapsulation();
	//将Client发来的数据包进行解封装。

};