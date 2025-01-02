#include <fstream>
using namespace std;
class Account
{
	friend ofstream;
	private:
	char ID[20];
	int password;
	char name[11];
	char user_ID[19];
	unsigned long int balance;
	unsigned long day_takecash;
    short day_count;
	bool stage;
	public:
    Account(char id[]);//创建账户的初始
    Account();
    void Save(Account &a);//信息存储
    void Record(int record);//记录存储

    bool PasswordTest();//检测密码
    string ShowName();//用于输出名字

    void SeeBalance();//1-余额查询
    int WithdrawCash();//2-取现金
    int DepositFunds();//3-存现金
    int transfer();//4-转账
    int ShowrRecord();//5-显示存取记录
    int tranPassword();//6-修改密码
};