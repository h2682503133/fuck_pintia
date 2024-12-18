#include<iostream>
using namespace std;

int Num[10000];
int how[10000];
int ss[10000];

int pfh(int i)
{
    int sum=0;
    while(i!=0)
    {
        sum+=(i%10)*(i%10);
        i/=10;
    }
    return sum;
}
int test(int i,int *each,int *count)
{
    for(int j=0;j<*count-1;j++)
        if(each[j]==i)
        {
            return 0;
            break;
        }
    each[*count]=i;
    (*count)++;
    if(i==1)return 1;
    else return test(pfh(i),each,count);
}
void independent(int n,int j)
{
    int temp=n;
    while(temp>1)
    {
        temp=pfh(temp);
        for(int i=0;i<j;i++)
        {
            if(temp==Num[i])Num[i]=0;
        }
    }
}
int main()
{
    int j=0;
    int temp;
    int start,end;
    ss[0]=2;
    cin>>start>>end;
    for(int i=3,j=1;i<=end;i++)
    {
        for(int k=0;k<=j;k++)
        {
            if(k==j){ss[k]=i;j++;break;}
            else if(i%ss[k]==0)break;
        }
    }

    for(int i=start;i<=end;i++)
    {
        int each[10000]={0};
        int count=0;
        
        temp=test(i,each,&count);
        if(temp)
        {
            Num[j]=i;
            for(int k=0;ss[k];k++)
            {
                if(ss[k]==i){how[j]=2*(count-1);}
            }
            if(how[j]==0)how[j]=count-1;
            j++;
        }
        count=0;
    }
    for(int i=0;i<j;i++)
    {
        independent(Num[i],j);
    }
    for(int i=0;i<j;i++)
    {
        if(Num[i])cout<<Num[i]<<' '<<how[i]<<endl;
    }
    if(j==0)cout<<"SAD";
}
