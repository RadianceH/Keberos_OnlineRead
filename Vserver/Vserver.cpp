#include "Vserver.h"

//获取当前时间戳
string Vserver::V_TS()
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

//对最终要发回Client的数据包进行封装加密
string Vserver::V_CDataEncapsulation()
{

}

//将Client发来的数据包进行解封装
void Vserver::V_CDataDeEncapsulation()
{

}

int Vserver::function()
{
	
}

bool Vserver::Is_TrueClient()
{

}

bool Vserver::getbook()
{

}
void Vserver::V_CDataDeEnread()
{

}
string Vserver::V_CDataEnread()
{

}