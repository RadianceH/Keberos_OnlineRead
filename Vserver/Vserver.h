#pragma once
#include <string>
#include <ctime>
using namespace std;

class Vserver {
public:
	Vserver(int Port);
	//socket�ȴ���������ʵ�ִ������߳�Ϊ��client�ṩ����
	
	/*����Ϊ���幦�ܺ���*/
	bool login(string CID, string CPWD);
	//��½���ܺ���
    bool readbook();
	//�Ķ����ܺ�����
	bool nextpage();
	//��һҳ���ܺ�����
	bool prepage();
	//��һҳ���ܺ�����
	bool collect();
	//�ղ��鼮����
	void exit();
	//�˳����ܺ�����
	Vserver();
	//���캯��
	~Vserver();
	//��������
private:
	string V_CDataEncapsulation();
	//������Ҫ����Client�����ݰ����з�װ���ܡ�
	string V_CDataDeEncapsulation();
	//��Client���������ݰ����н��װ��
	void Receive();
	//��Ϣ��Ӧ��������Խ��յ������ݣ�ѡ����Ӧ�ĺ������л�Ӧ��
	string V_TS();
	//��ȡ��ǰTSʱ���
};