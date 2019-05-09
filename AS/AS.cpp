#include"AS.h"
#include<iostream>

//获取当前时间戳
string ASserver::AS_TS()
{
	time_t now;
	struct tm pt;
	time(&now);
	localtime_s(&pt, &now);
	string ts;
	string year, mon, day, hour, min, sec;
	year = to_string(pt.tm_year - 100);
	if (year.length() == 1)
	{
		year = "0" + year;
	}
	mon = to_string(pt.tm_mon + 1);
	if (mon.length() == 1)
	{
		mon = "0" + mon;
	}
	day = to_string(pt.tm_mday);
	if (day.length() == 1)
	{
		day = "0" + day;
	}
	hour = to_string(pt.tm_hour);
	if (hour.length() == 1)
	{
		hour = "0" + hour;
	}
	min = to_string(pt.tm_min);
	if (min.length() == 1)
	{
		min = "0" + min;
	}
	sec = to_string(pt.tm_sec);
	if (sec.length() == 1)
	{
		sec = "0" + sec;
	}
	ts = year + mon + day + hour + min + sec;
	return ts;
}

//封装加密生成Client与TGS验证所需要的TicketTGS   格式：(KeyCTGS+IDC+CAddr+IDTGS+ts2+lifetime2+0填充) 使用KeyCTGS加密
string ASserver::GetTicketTGS()
{
	string ticketTGS="";
	string ts2 = AS_TS();
	ticketTGS += KeyCTGS;
	ticketTGS += IDC;
	ticketTGS += ADC;
	ticketTGS += IDTGS;
	ticketTGS += ts2;
	ticketTGS += lifet;
	ticketTGS += "0";
	//加密
	return ticketTGS;

}

//封装加密整合生成最终要发回Client的数据包 格式：(KeyCTGS+IDTGS+ts2+lifetime2+TicketTGS+0填充)
string ASserver::AS_CDataEncapsulation()
{
	string trueticket = "";
	string ts2;
	ts2.assign(GetTicketTGS(),30,12);
	trueticket += KeyCTGS;
	trueticket += IDTGS;
	trueticket += ts2;
	trueticket += lifet;
	trueticket += GetTicketTGS();
	trueticket += "0000";
	return trueticket;
}

//将Client发来的数据包进行解封装 (IDC,IDTGS,TS1)
void ASserver::AS_CDataDeEncapsulation()
{
	IDC.assign(c2as,0,4);
	IDTGS.assign(c2as,4,4);
}

void ASserver::GetKeyCTGS()
{

}