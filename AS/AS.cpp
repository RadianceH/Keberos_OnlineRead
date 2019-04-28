#include"AS.h"
#include<iostream>

string ASserver::GetTicketTGS(string KeyCTGS, string IDC, string CAddr, string IDTGS, int LifeTime2)
//封装加密生成Client与TGS验证所需要的TicketTGS
{
	string ticketTGS="";
	ticketTGS += KeyCTGS;
	ticketTGS += IDC;
	
	ticketTGS += LifeTime2;
	ticketTGS += "";
	return ticketTGS;
}

string ASserver::AS_CDataEncapsulation(string TicketTGS, string KeyCTGS, string IDTGS, int LifeTime2)
//封装加密整合生成最终要发回Client的数据包
{

}

string ASserver::AS_CDataDeEncapsulation()
//将Client发来的数据包进行解封装
{
	
}