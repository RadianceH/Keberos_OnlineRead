#pragma once
#include<string>
#include<WinSock2.h>
#include <iostream>
#include <ctime>
using namespace std;

 class Client {
 public:
	 string IDC;
	 string CAddr;
	 SOCKET ClientSocket;
	 Client(string Addr);
	 //���캯����new Client���Գ�Ա�����û�ID�Լ��û�IP��ַ��ֵ��
	 void SocketLink(string SockAddr, int SockPort);
	 //�׽���ͨ�ź���������IP�˿ڷ���socket���ӡ�
	 void SendData(string info);
	 //ͨ�������ӵ��׽��֣���������
	 string RecvData();
	 //ͨ�������ӵ��׽��֣���������
	 void ExitSocket();
	 //�Ͽ������ӵ��׽���
	 void Authentication();
	 //Keberos��֤��������̵���AS��֤������TGS��֤������Ӧ�÷�������֤�����������Keberos��֤���̣�������֤Client�ͻ����ܹ���������������
	 void LinkAS(string ASAddr, int ASPort);
	 //AS������֤������ͨ���׽���ͨ�ź�����AS����socketͨ�ţ���ͨ����Ӧ�����ݷ�װ���������ݽ�⺯�������AS��������֤������
	 void LinkTGS(string TGSAddr, int TGSPort);
	 //TGS������֤������ͨ���׽���ͨ�ź�����TGS����socketͨ�ţ���ͨ����Ӧ�����ݷ�װ���������ݽ�⺯�������TGS��������֤������
	 void LinkV(string VAddr, int VPort);
	 //Ӧ�÷�����������֤������ͨ���׽���ͨ�ź�����VӦ�÷���������socketͨ��, ��ͨ����Ӧ�Ĳ�ͨ����Ӧ�����ݷ�װ���������ݽ�⺯�������ͻ���������������֤������

    /*����Ϊ���幦�ܺ���*/
	bool login();
	bool readbook();
	bool nextpage();
	bool prepage();
	bool collect();
	bool exit();
	Client();
	//���캯��
	~Client();
	//��������
 private:
	/*����Ϊ��װ��غ���*/
	 string C_ASDataEncapsulation(string IDTGS);
	 //ASͨ�����ݷ�װ����������Client��AS���跢�͵����ݽ��з�װ���ܡ�
	 string C_ASDataDeEncapsulation();
	 //ASͨ�����ݽ��װ����������AS���������ݰ������н��ܲ�֡�
	 string C_TGSDataEncapsulation(string IDV, string TicketTGS);
	 //TGSͨ�����ݷ�װ����������Client��TGS���跢�͵����ݽ��з�װ���ܡ�
	 string C_TGSDataDeEncapsulation();
	 //TGSͨ�����ݽ��װ����������TGS���������ݰ������н��ܲ�֡�
	 string C_VDataEncapsulation(string TicketV);
	 //�ͻ�������ͨ�����ݷ�װ����������Client����������跢�͵����ݽ��з�װ���ܡ�
	 string C_VDataDeEncapsulation();
	 //�ͻ�������ͨ�����ݽ��װ����������TGS���������ݰ������н��ܲ�֡�
	 string C_TS();
	 //��ȡ��ǰTSʱ���
};