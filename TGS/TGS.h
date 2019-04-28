#pragma once
#include<string>
using namespace std;

class TGSserver {
public:
	TGSserver(int Port);
	//socket等待监听，可实现创建多线程为多client提供服务。
	string GetKeyCV(string TGSID);
	//查找数据库，根据Client发来的VID得到Client与V的会话密钥。
private:
	string GetTicketV(string KeyCV, string IDC, string CAddr, string IDV, int LifeTime4);
	//封装加密生成Client与V验证所需要的TicketV。
	string TGS_CDataEncapsulation(string TicketV, string KeyCV, string IDV, int LifeTime4);
	//封装加密整合生成最终要发回Client的数据包。
	string TGS_CDataDeEncapsulation();
	//将Client发来的数据包进行解封装。


};