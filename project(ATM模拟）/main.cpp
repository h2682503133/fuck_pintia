#include "Account.cpp"
int main()
{
	int mode;
	bool stage_isfile=0;
	bool stage_end=0;
	int l;//����cin���
	string id;
	Account this_account;//�Ƚ��г�ʼ��
    //��ӭ
	cout<<"********************************\n***   ��ӭʹ��ATM��������    ***\n***    �������˺�ID�忨��    ***\n********************************\n";
	//�����˺ţ��ж����룬����
    cout<<"������ID";
	cin>>id;
	while(id.length()<19)
	{
		cout<<"λ�����������Ƿ�������ȷ\n";
		cin>>id;
	}
	while(!stage_isfile)
	{
		fstream infile("Account\\"+id+".dat",ios_base::in);
		if(infile)stage_isfile=1;
		else
		{
			string temp;
			cout<<"�˻������ڣ��Ƿ��½��˻���\n���� 'Yes' or 'No'";
			cin>>temp;
			if(temp=="Yes")
			{
				Account new_account(id.data());
				this_account=new_account;
				break;
			}
			else if(temp=="No")
			{
				cout<<"�����������˺�\n";
				cin>>id;
			}
			while(id.length()<19)
			{
				cout<<"λ�����������Ƿ�������ȷ\n";
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
	cout<<"��½�ɹ�!\n�ܸ�����Ϊ������";
	cout<<this_account.ShowName()<<"(����/Ůʿ)\n";
	do
	{
		
		cout<<"*******************************\n***          Ŀ¼           ***\n***       0-�˿�            ***\n***       1-����ѯ        ***\n***       2-��ȡ�ֽ�        ***\n***       3-�����ֽ�        ***\n***       4-ת��            ***\n***       5-��ȡ��¼��ѯ    ***\n***       6-�޸�����        ***\n***  ���������������ѡ��   ***\n*******************************";
		cout<<"\nѡ��ģʽ";
		cin>>mode;
		system("CLS");
		switch(mode)
		{
			case 0:cout<<"�����˿�\n";break;
			case 1:this_account.SeeBalance();break;
			case 2:this_account.WithdrawCash();break;
			case 3:this_account.DepositFunds();break;
			case 4:this_account.transfer();break;
			case 5:this_account.ShowrRecord();break;
			case 6:this_account.tranPassword();break;
			default:cout<<"������0~6��������\n";
		}
		cout<<"����0����\n";
		cin>>l;
		system("CLS");

	}while(mode!=0);
	cout<<"�˿��ɹ�\n��ӭ�����´�ʹ��\n����0�˳�\n";
	cin>>l;
}
