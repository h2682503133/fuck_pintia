#include <iostream>
#include <cstring>
#include "Account.h"
#define start_balance 10000//��ʼ���
#define Max_count_test 3 //�����Դ���
#define start_password 114514//��ʼ����
#define Max_daily_withdraw 5000//������ȡ�������
#define Max_daily_count 3//������ȡ��������
using namespace std;
void Account::Save(Account &a)//���ݴ洢
{
	ofstream outfile("Account\\"+string(a.ID)+".dat",ios_base::out|ios_base::binary);
	outfile.write((char*)&a,sizeof(Account));
	outfile.close();
}
Account::Account(char id[])//����IDʱΪ�½��˻�
{
	int a;//���ں�������
	string temp;//��ݺ��ݴ�
	strcpy(ID,id);
	cout<<"��������\n";
	cin>>name;
	cout<<"����18λ���֤��\n";
	cin>>temp;
	while(temp.length()!=18)
	{
		cout<<"������18λ���֤��\n";
		cin>>temp;
	}
	strcpy(user_ID,temp.data());
	cout<<"Ĭ������Ϊ"<<start_password<<endl;
	password=start_password;
	balance = start_balance;
	day_takecash=0;
	day_count=0;
	stage=0;
	Save(*this);
	cout<<"����0����";
	cin>>a;
}
Account::Account() //����һ���յĹ��캯�����ڳ�ʼ�� ͨ����ȡ����˻�ֱ�Ӹ��ǵ�
{
}
bool Account::PasswordTest()//����ֱ�Ӷ�ȡ��Ϣ����������
{
	int a;//����������������û�����ʱ��
	int password_in;
	if(stage==1)
	{
		cout<<"�Բ��𣬸ÿ��ѱ���\n";
		cout<<"����0����";
		cin>>a;
		return true;
	}
	else
	{
		int count=1;
		cout<<"����������\n";
		cin>>password_in;
		for(;count<Max_count_test;count++)
		{
			if(password==password_in)break;
			printf("��������㻹��%d�λ���\n",3-count);
			cin>>password_in;
		}
		if(count>=3)
		{
			stage=1;
			cout<<"�������3�Σ��ÿ��ѱ���\n";
			Save(*this);
			cout<<"����0����";
			cin>>a;
			return true;
		}
		else return false;
	}
}

void Account::Record(int a)
{
	ofstream outfile("Data\\"+string(ID)+".txt",ios_base::app);
	if(!outfile)ofstream outfile("Data\\"+string(ID)+".txt",ios_base::out);
	outfile<<to_string(a)<<endl;
	outfile.close();
}
string Account::ShowName()
{
	return string(name);
}
void Account::SeeBalance()//1-����ѯ
{
	cout<<balance;
}
int Account::tranPassword()//6-�޸�����
{	
	int once;
	int twice;
	cout<<"�������룬������0����\n";
	do
	{
		do
		{
			cout<<"������6λ��������\n";
			cin>>once;
			if(once==0)return 0;
		} while (once<100000||once>=1000000);
		cout<<"���ٴ�����";
		cin>>twice;
		if(once==twice)break;
		cout<<"�������벻��������������";
	} while (once!=twice);
	password=once;
	Save(*this);
	cout<<"�޸ĳɹ�";
	return 0;
}
int Account::WithdrawCash()//2-ȡ��
{
	int a;
	cout<<"������ȡ����(100�ı���)\n�ҵ��ս�����"<<Max_daily_withdraw<<"\nÿ�մ���������"<<Max_daily_count<<"\n������0����\n";
	cin>>a;
	if(a==0)return 0;
	if(day_takecash>=Max_daily_withdraw)
	{
		cout<<"����ȡ������ѵ�������\n������������";
		return 0;
	}
	else if(day_count>=Max_daily_count)
	{
		cout<<"����ȡ������Ѵﵽ����\n������������";
		return 0;
	}
	while(a%100||balance<a||(a+day_takecash)>Max_daily_withdraw||a<0)
	{
		if(a<0)cout<<"������һ������0����\n";
		else
		{
			if((a+day_takecash)>Max_daily_withdraw)cout<<"�������������\n";
			if(balance<a)cout<<"���㣬�뻻����Ŀ������0����\n";
			if(a%100)cout<<"������100�ı���\n";
		}
		cin>>a;
		if(a==0)return 0;
	}
	balance-=a;
	day_takecash+=a;
	day_count++;
	Record(-a);
	Save(*this);
	cout<<"ȡ��ɹ�";
	return 0;
}
int Account::DepositFunds()//3-���
{
	int a;
	cout<<"����������(100�ı���)";
	cin>>a;
	if(a==0)return 0;
	while(a<0||a%100)
	{
		if(a<0)cout<<"������һ������0����\n";
		if(a%100)cout<<"������100�ı���\n";
		cin>>a;
		if(a==0)return 0;
	}
	balance+=a;
	Record(a);
	Save(*this);
	cout<<"���ɹ�";
	return 0;
}
int Account::transfer()//4-ת��
{
	string id1,id2;
	int much;
	Account other_account;//��������
	cout<<"������ת���˺�\n������0�˳�";
	
	do
	{
		bool stage_isfile=0;//���ڼ���˻��Ƿ����
		cin>>id1;
		while(id1==string(ID))
		{
			cout<<"�޷�ת�˸��Լ�������������\n";
			cin>>id1;
		}
		if(id1=="0")return 0;
		//����˻��Ƿ���ڣ�����������������
		while(!stage_isfile)
		{
			fstream infile("Account\\"+id1+".dat",ios_base::in);
			if(infile)stage_isfile=1;
			else
			{
				cout<<"�˺Ų����ڣ����������������0�˳�\n";
				cin>>id1;
				while(id1==string(ID))
				{
					cout<<"�޷�ת�˸��Լ�������������\n";
					cin>>id1;
				}
				if(id1=="0")return 0;
			}
		}
		//��ȡ�ļ����ݲ����ɶ���
		fstream infile("Account\\"+id1+".dat",ios_base::in);
		infile.read((char*)&other_account,sizeof(Account));
		infile.close();

		cout<<"��������һ���˺�ȷ��\n";
		cin>>id2;
		if(id1!=id2)cout<<"�����˺Ų�ͬ������������\n";
	}while(id1!=id2);
	
	cout<<"��������(����)\n";//ת��
	cin>>much;
	
	while(much<0||balance<much)
	{
		if(much<0)cout<<"������һ������0������\n";
		if(balance<much)cout<<"���㣬�뻻����Ŀ������0����\n";
		if(much==0)return 0;
		cin>>much;
	}
	balance-=much;
	other_account.balance+=much;
	other_account.Save(other_account);
	Save(*this);
	printf("ת�˳ɹ�����ת��%dԪ",much);
	return 0;
}
int Account::ShowrRecord()//5-��ѯ��ȡ��¼
{
	ifstream infile("Data\\"+string(ID)+".txt",ios_base::in);
	if(!infile)
	{
		cout<<"��������";
		return 0;
	}
	while(!infile.eof())
	{
		string temp;
		infile>>temp;
		cout<<temp<<endl;
	}
	infile.close();
	return 0;
}
