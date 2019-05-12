#include "TGS.h"
#include "des.h"
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
	ts4 = TGS_TS();
	string TV = "";
	TV += KeyCV;
	TV += IDC;
	TV += ADC;
	TV += IDV;
	TV += ts4;
	TV += lifet;
	TV += "0";
	string a;
	string temp;
	for (int i = 0; i < 6; i++)
	{
		a.assign(TV, 0 + 8 * i, 8);
		temp += jiami(a, KeyCV);
	}
	return temp;
}

//封装加密整合生成最终要发回Client的数据包 格式:(KeyCV+IDC+TS4+TicketV)
string TGSserver::TGS_CDataEncapsulation()
{
	string truetv = "";
	string tv = GetTicketV();
	truetv += KeyCV;
	truetv += IDV;
	truetv += ts4;
	truetv += tv;
	cout << "KeyCV:" << KeyCV << " IDV:" << IDV << " ts4:" << ts4 << " TicketV:" << GetTicketV() << endl;
	string a;
	string temp;
	for (int i = 0; i < 9; i++)
	{
		a.assign(truetv, 0 + 8 * i, 8);
		temp += jiami(a, KeyCTGS);
	}
	return temp;
}

//将Client发来的数据包进行解封装
void TGSserver::TGS_CDataDeEncapsulation()
{
	IDV.assign(c2tgs,0,4);
	ticketTGS.assign(c2tgs,4,48);
	Authenticator.assign(c2tgs,52,32);
	TGS_ticket();
	TGS_authenticator();
}

//解封ticketTGS
void TGSserver::TGS_ticket()
{
	string a;
	string temp;
	for (int i = 0; i < 6; i++)
	{
		a.assign(ticketTGS, 0 + 8 * i, 8);
		temp += jiemi(a, KeyCTGS);
	}
	IDC.assign(temp,8,4);
	ADC.assign(temp,12,15);
}

//解封autnenticatorc
void TGSserver::TGS_authenticator()
{
	string a;
	string temp;
	for (int i=0;i<4;i++)
	{
		a.assign(Authenticator,0+8*i,8);
		temp += jiemi(a, KeyCTGS);
	}
	IDC.assign(temp,0,4);
	ADC.assign(temp,4,15);
}
bool TGSserver::Is_TureClient()
{
	return true;
}
void TGSserver::GetKeyCV()
{
		MYSQL *mysql = new MYSQL;
		MYSQL_FIELD *fd;
		char field[32][32];
		MYSQL_RES *res;
		MYSQL_ROW column;
		char query[150];
		mysql_init(mysql);
		mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "gbk");
		if (!(mysql_real_connect(mysql, "127.0.0.1", "root", "root", "tgsserver", 3306, NULL, 0)))
		{
			cout << "ERROR" << endl;
		}
		else
		{
			cout << "connect successfully" << endl;
		}
		char ccc[10];
		strcpy_s(ccc, IDV.c_str());
		sprintf_s(query, "SELECT KeyV from kkkey where IDV='%s'", ccc);
		if (mysql_query(mysql, query))
		{
			cout << mysql_error(mysql) << endl;
		}
		else
		{
			if (!(res = mysql_store_result(mysql)))
			{
				cout << "errrr" << endl;

			}
			else
			{
				column = mysql_fetch_row(res);
				cout << column[0] << endl;
				KeyCV = column[0];
			}
		}

	}