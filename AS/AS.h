#pragma once
#include<string>
#include<WinSock2.h>
#include <ctime>
using namespace std;

class ASserver {
public:
	ASserver(int Port);
	//socket�ȴ���������ʵ�ִ������߳�Ϊ��client�ṩ����
	string GetKeyCTGS(string TGSID);
	//�������ݿ⣬����Client������TGSID�õ�Client��TGS�ĻỰ��Կ
	ASserver();
	//���캯��
	~ASserver();
	//��������
private:
	string GetTicketTGS(string KeyCTGS, string IDC, string CAddr, string IDTGS, int LifeTime2);
	//��װ��������Client��TGS��֤����Ҫ��TicketTGS
	string AS_CDataEncapsulation(string TicketTGS, string KeyCTGS, string IDTGS, int LifeTime2);
	//��װ����������������Ҫ����Client�����ݰ�
	string AS_CDataDeEncapsulation();
	//��Client���������ݰ����н��װ��
	string AS_TS();
	//��ȡ��ǰTSʱ���
};