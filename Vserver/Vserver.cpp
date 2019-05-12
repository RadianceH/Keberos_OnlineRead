#include "Vserver.h"
#include "des.h"
#include <iostream>
#include<functional>
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
	string v2c;
	v2c += ts5;
	v2c += "0000";
	cout << v2c << endl;
	return v2c;
}

//将Client发来的数据包进行解封装
void Vserver::V_CDataDeEncapsulation(string data)
{
	string temp;
	temp.assign(data,48,32);
	string a;
	string b;
	for (int i = 0; i < 4; i++)
	{
		a.assign(temp, 0 + 8 * i, 8);
		b += jiemi(a, KeyCV);
	}
	IDC.assign(b,0,4);
	ts5.assign(b,19,12);
	string t1;
	t1.assign(ts5,0,6);
	string t2;
	t2.assign(ts5,6,6);
	int ts;
	ts = atoi(t2.c_str());
	ts++;
	string v = to_string(ts);
	while (v.length() < 6)
		v = "0" + v;
	ts5 = t1+ v;
}

int Vserver::function()
{
	return 0;
}

bool Vserver::Is_TrueClient(string data)
{
	string a;
	string b;
	string temp;
	temp.assign(data,0,48);
	for (int i = 0; i < 6; i++)
	{
		a.assign(temp, 0 + 8 * i, 8);
		b += jiemi(a, KeyCV);
	}
	string tempidc;
	tempidc.assign(8,4);
	if (tempidc == IDC)
		return true;
	else
		return false;
}

bool Vserver::getbook()
{
	return true;
}
void Vserver::V_CDataDeEnread()
{
	
}
string Vserver::V_CDataEnread()
{
	string a;
	return a;
}

void Vserver::GetSign()
{
	rsa.d = (BigInteger)"036EA40F5FB2487E15B3BC04C527ECBDED4FF999";
	rsa.n = (BigInteger)"036EA40F5FB2487E15B3BC04C527ECBDED4FF999";
	hash<string> hash_str;
	int ii = hash_str(signdata);
	char qqq[100];
	itoa(ii, qqq, 10);
	string str;
	str.assign(qqq);
	BigInteger c = rsa.encryptByPrivate(str);
	sign = c.toString();
}