#pragma once
#include<string>
using namespace std;

class TGSserver {
public:
	TGSserver(int Port);
	//socket�ȴ���������ʵ�ִ������߳�Ϊ��client�ṩ����
	string GetKeyCV(string TGSID);
	//�������ݿ⣬����Client������VID�õ�Client��V�ĻỰ��Կ��
private:
	string GetTicketV(string KeyCV, string IDC, string CAddr, string IDV, int LifeTime4);
	//��װ��������Client��V��֤����Ҫ��TicketV��
	string TGS_CDataEncapsulation(string TicketV, string KeyCV, string IDV, int LifeTime4);
	//��װ����������������Ҫ����Client�����ݰ���
	string TGS_CDataDeEncapsulation();
	//��Client���������ݰ����н��װ��


};