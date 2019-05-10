#include "TGS.h"
#include <iostream>
//获取当前时间戳
string TGSserver::TGS_TS()
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

//封装加密生成Client与V验证所需要的TicketV 格式:(KeyCV+IDC+CAddr+IDV+TS4+lifetime4+0填充) KeyCV加密
string TGSserver::GetTicketV()
{
	string ts4 = TGS_TS();
	string TV = "";
	TV += KeyCV;
	TV += IDC;
	TV += ADC;
	TV += IDV;
	TV += ts4;
	TV += lifet;
	TV += "0";
	return TV;
}

//封装加密整合生成最终要发回Client的数据包 格式:(KeyCV+IDC+TS4+TicketV)
string TGSserver::TGS_CDataEncapsulation()
{
	string truetv = "";
	string ts4;
	ts4.assign(GetTicketV(),31,12);
	truetv += KeyCV;
	truetv += IDV;
	truetv += ts4;
	truetv += GetTicketV();
	cout << "KeyCV:" << KeyCV << " IDV:" << IDV << " ts4:" << ts4 << " TicketV:" << GetTicketV() << endl;
	return truetv;
}

//将Client发来的数据包进行解封装
void TGSserver::TGS_CDataDeEncapsulation()
{
	IDV.assign(c2tgs,0,4);
	ticketTGS.assign(c2tgs,4,15);
	Authenticator.assign(c2tgs,52,32);
	TGS_ticket();
	TGS_authenticator();
}

//解封ticketTGS
void TGSserver::TGS_ticket()
{
	IDC.assign(ticketTGS,8,4);
	ADC.assign(ticketTGS,12,15);
}

//解封autnenticatorc
void TGSserver::TGS_authenticator()
{
	IDC.assign(Authenticator,0,4);
	ADC.assign(Authenticator,4,15);
}
bool TGSserver::Is_TureClient()
{
	return true;
}
void TGSserver::GetKeyCV()
{
	KeyCV = "03030505";
}