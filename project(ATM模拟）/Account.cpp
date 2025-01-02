#include <iostream>
#include <cstring>
#include "Account.h"
#define start_balance 10000//初始金额
#define Max_count_test 3 //最大测试次数
#define start_password 114514//初始密码
#define Max_daily_withdraw 5000//单日提取金额上限
#define Max_daily_count 3//单日提取次数上限
using namespace std;
void Account::Save(Account &a)//数据存储
{
	ofstream outfile("Account\\"+string(a.ID)+".dat",ios_base::out|ios_base::binary);
	outfile.write((char*)&a,sizeof(Account));
	outfile.close();
}
Account::Account(char id[])//传入ID时为新建账户
{
	int a;//用于后续输入
	string temp;//身份号暂存
	strcpy(ID,id);
	cout<<"输入名字\n";
	cin>>name;
	cout<<"输入18位身份证号\n";
	cin>>temp;
	while(temp.length()!=18)
	{
		cout<<"请输入18位身份证号\n";
		cin>>temp;
	}
	strcpy(user_ID,temp.data());
	cout<<"默认密码为"<<start_password<<endl;
	password=start_password;
	balance = start_balance;
	day_takecash=0;
	day_count=0;
	stage=0;
	Save(*this);
	cout<<"输入0继续";
	cin>>a;
}
Account::Account() //设置一个空的构造函数用于初始化 通过读取获得账户直接覆盖掉
{
}
bool Account::PasswordTest()//用于直接读取信息后的密码测试
{
	int a;//用于锁卡后输入给用户缓冲时间
	int password_in;
	if(stage==1)
	{
		cout<<"对不起，该卡已被锁\n";
		cout<<"输入0继续";
		cin>>a;
		return true;
	}
	else
	{
		int count=1;
		cout<<"请输入密码\n";
		cin>>password_in;
		for(;count<Max_count_test;count++)
		{
			if(password==password_in)break;
			printf("输入错误，你还有%d次机会\n",3-count);
			cin>>password_in;
		}
		if(count>=3)
		{
			stage=1;
			cout<<"输入错误3次，该卡已被锁\n";
			Save(*this);
			cout<<"输入0继续";
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
void Account::SeeBalance()//1-余额查询
{
	cout<<balance;
}
int Account::tranPassword()//6-修改密码
{	
	int once;
	int twice;
	cout<<"输入密码，或输入0返回\n";
	do
	{
		do
		{
			cout<<"请输入6位数字密码\n";
			cin>>once;
			if(once==0)return 0;
		} while (once<100000||once>=1000000);
		cout<<"请再次输入";
		cin>>twice;
		if(once==twice)break;
		cout<<"两次输入不符，请重新输入";
	} while (once!=twice);
	password=once;
	Save(*this);
	cout<<"修改成功";
	return 0;
}
int Account::WithdrawCash()//2-取款
{
	int a;
	cout<<"请输入取款金额(100的倍数)\n且单日金额不超过"<<Max_daily_withdraw<<"\n每日次数不超过"<<Max_daily_count<<"\n或输入0返回\n";
	cin>>a;
	if(a==0)return 0;
	if(day_takecash>=Max_daily_withdraw)
	{
		cout<<"今日取款余额已到达上限\n请明天再来吧";
		return 0;
	}
	else if(day_count>=Max_daily_count)
	{
		cout<<"今日取款次数已达到上限\n请明天再来吧";
		return 0;
	}
	while(a%100||balance<a||(a+day_takecash)>Max_daily_withdraw||a<0)
	{
		if(a<0)cout<<"请输入一个大于0的数\n";
		else
		{
			if((a+day_takecash)>Max_daily_withdraw)cout<<"超过单日最大金额\n";
			if(balance<a)cout<<"余额不足，请换个数目或输入0返回\n";
			if(a%100)cout<<"请输入100的倍数\n";
		}
		cin>>a;
		if(a==0)return 0;
	}
	balance-=a;
	day_takecash+=a;
	day_count++;
	Record(-a);
	Save(*this);
	cout<<"取款成功";
	return 0;
}
int Account::DepositFunds()//3-存款
{
	int a;
	cout<<"请输入存款金额(100的倍数)";
	cin>>a;
	if(a==0)return 0;
	while(a<0||a%100)
	{
		if(a<0)cout<<"请输入一个大于0的数\n";
		if(a%100)cout<<"请输入100的倍数\n";
		cin>>a;
		if(a==0)return 0;
	}
	balance+=a;
	Record(a);
	Save(*this);
	cout<<"存款成功";
	return 0;
}
int Account::transfer()//4-转账
{
	string id1,id2;
	int much;
	Account other_account;//创建对象
	cout<<"请输入转账账号\n或输入0退出";
	
	do
	{
		bool stage_isfile=0;//用于检测账户是否存在
		cin>>id1;
		while(id1==string(ID))
		{
			cout<<"无法转账给自己，请重新输入\n";
			cin>>id1;
		}
		if(id1=="0")return 0;
		//检测账户是否存在，若不存在则重输入
		while(!stage_isfile)
		{
			fstream infile("Account\\"+id1+".dat",ios_base::in);
			if(infile)stage_isfile=1;
			else
			{
				cout<<"账号不存在，请重新输入或输入0退出\n";
				cin>>id1;
				while(id1==string(ID))
				{
					cout<<"无法转账给自己，请重新输入\n";
					cin>>id1;
				}
				if(id1=="0")return 0;
			}
		}
		//读取文件内容并生成对象
		fstream infile("Account\\"+id1+".dat",ios_base::in);
		infile.read((char*)&other_account,sizeof(Account));
		infile.close();

		cout<<"请再输入一次账号确认\n";
		cin>>id2;
		if(id1!=id2)cout<<"两次账号不同，请重新输入\n";
	}while(id1!=id2);
	
	cout<<"请输入金额(整数)\n";//转账
	cin>>much;
	
	while(much<0||balance<much)
	{
		if(much<0)cout<<"请输入一个大于0的整数\n";
		if(balance<much)cout<<"余额不足，请换个数目或输入0返回\n";
		if(much==0)return 0;
		cin>>much;
	}
	balance-=much;
	other_account.balance+=much;
	other_account.Save(other_account);
	Save(*this);
	printf("转账成功，已转出%d元",much);
	return 0;
}
int Account::ShowrRecord()//5-查询存取记录
{
	ifstream infile("Data\\"+string(ID)+".txt",ios_base::in);
	if(!infile)
	{
		cout<<"暂无数据";
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
