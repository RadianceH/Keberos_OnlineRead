#include "TGS.h"

//��ȡ��ǰʱ���
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

string TGSserver::GetTicketV(string KeyCV, string IDC, string CAddr, string IDV, int LifeTime4)
//��װ��������Client��V��֤����Ҫ��TicketV
{

}

string TGSserver::TGS_CDataEncapsulation(string TicketV, string KeyCV, string IDV, int LifeTime4)
//��װ����������������Ҫ����Client�����ݰ�
{

}

string TGSserver::TGS_CDataDeEncapsulation()
//��Client���������ݰ����н��װ
{

}