#include "Account.cpp"
int main()
{
	int mode;
	bool stage_isfile=0;
	bool stage_end=0;
	int l;//用于cin间隔
	string id;
	Account this_account;//先进行初始化
    //欢迎
	cout<<"********************************\n***   欢迎使用ATM自助服务    ***\n***    请输入账号ID插卡！    ***\n********************************\n";
	//输入账号，判断密码，开户
    cout<<"请输入ID";
	cin>>id;
	while(id.length()<19)
	{
		cout<<"位数错误请检查是否输入正确\n";
		cin>>id;
	}
	while(!stage_isfile)
	{
		fstream infile("Account\\"+id+".dat",ios_base::in);
		if(infile)stage_isfile=1;
		else
		{
			string temp;
			cout<<"账户不存在，是否新建账户？\n输入 'Yes' or 'No'";
			cin>>temp;
			if(temp=="Yes")
			{
				Account new_account(id.data());
				this_account=new_account;
				break;
			}
			else if(temp=="No")
			{
				cout<<"请重新输入账号\n";
				cin>>id;
			}
			while(id.length()<19)
			{
				cout<<"位数错误请检查是否输入正确\n";
				cin>>id;
			}
		}
	}
	ifstream infile("Account\\"+id+".dat",ios_base::in);
	if(stage_isfile)
	{
		bool stage_lock;
		infile.read((char*)&this_account,sizeof(Account));
		stage_lock=this_account.PasswordTest();
		if(stage_lock)return -1;
	}

	system("CLS");
	cout<<"登陆成功!\n很高兴能为您服务";
	cout<<this_account.ShowName()<<"(先生/女士)\n";
	do
	{
		
		cout<<"*******************************\n***          目录           ***\n***       0-退卡            ***\n***       1-余额查询        ***\n***       2-提取现金        ***\n***       3-存入现金        ***\n***       4-转账            ***\n***       5-存取记录查询    ***\n***       6-修改密码        ***\n***  请以数字输入你的选择   ***\n*******************************";
		cout<<"\n选择模式";
		cin>>mode;
		system("CLS");
		switch(mode)
		{
			case 0:cout<<"正在退卡\n";break;
			case 1:this_account.SeeBalance();break;
			case 2:this_account.WithdrawCash();break;
			case 3:this_account.DepositFunds();break;
			case 4:this_account.transfer();break;
			case 5:this_account.ShowrRecord();break;
			case 6:this_account.tranPassword();break;
			default:cout<<"请输入0~6任意整数\n";
		}
		cout<<"输入0继续\n";
		cin>>l;
		system("CLS");

	}while(mode!=0);
	cout<<"退卡成功\n欢迎您的下次使用\n输入0退出\n";
	cin>>l;
}
