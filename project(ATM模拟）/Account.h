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
    Account(char id[]);//�����˻��ĳ�ʼ
    Account();
    void Save(Account &a);//��Ϣ�洢
    void Record(int record);//��¼�洢

    bool PasswordTest();//�������
    string ShowName();//�����������

    void SeeBalance();//1-����ѯ
    int WithdrawCash();//2-ȡ�ֽ�
    int DepositFunds();//3-���ֽ�
    int transfer();//4-ת��
    int ShowrRecord();//5-��ʾ��ȡ��¼
    int tranPassword();//6-�޸�����
};