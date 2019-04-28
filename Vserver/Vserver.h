#pragma once
#include<string>
using namespace std;

class Vserver {
public:
	Vserver(int Port);
	//socket等待监听，可实现创建多线程为多client提供服务。
	
	/*以下为具体功能函数*/
	bool login(string CID, string CPWD);
	//登陆功能函数
    bool readbook();
	//阅读功能函数。
	bool nextpage();
	//下一页功能函数。
	bool prepage();
	//上一页功能函数。
	bool collect();
	//收藏书籍函数
	void exit();
	//退出功能函数。

private:
	string V_CDataEncapsulation();
	//对最终要发回Client的数据包进行封装加密。
	string V_CDataDeEncapsulation();
	//将Client发来的数据包进行解封装。
	void Receive();
	//消息响应函数，针对接收到的数据，选择相应的函数进行回应。

};