#include"AS.h"
#include<iostream>

string ASserver::GetTicketTGS(string KeyCTGS, string IDC, string CAddr, string IDTGS, int LifeTime2)
//��װ��������Client��TGS��֤����Ҫ��TicketTGS
{
	string ticketTGS="";
	ticketTGS += KeyCTGS;
	ticketTGS += IDC;
	
	ticketTGS += LifeTime2;
	ticketTGS += "";
	return ticketTGS;
}

string ASserver::AS_CDataEncapsulation(string TicketTGS, string KeyCTGS, string IDTGS, int LifeTime2)
//��װ����������������Ҫ����Client�����ݰ�
{

}

string ASserver::AS_CDataDeEncapsulation()
//��Client���������ݰ����н��װ
{
	
}