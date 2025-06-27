#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string modize(string &name)
{
    long unsigned int longth=name.size();
    char A[longth+5000];
    int test1=0,test2=0;
    int j=0;
    for(long unsigned int i=0;i<longth;i++)
    {
        char result=0;
        char temp=name.data()[i];
        if(temp=='_')
        {
            test1=1;
            result=temp;
        }
        if(temp>=97&&temp<=122)
        {
            result=temp-32;
            test2=1;
        }
        else if((temp>=65||temp<=90)&&test1==0&&test2==1)
        {
            A[j]='_';
            //test2=0; //悲报本人因此行代码痛失18分
            j++;
            result=temp;
        }
        else if(temp>=65||temp<=90)
        {
            result=temp;
        }
        
        
        A[j]=result;
        j++;
    }
    A[j]=0;
    return string(A);
}

int main()
{
    int T;
    cin>>T;
    vector<string> input;
    vector<string> output;
    set<string> test;
    for(int i=0;i<T;i++)
    {
        string temp;
        cin>>temp;
        temp=modize(temp);
        cout<<temp<<endl;
        if(test.count(temp)==0)
        {
            test.insert(temp);
            output.push_back(temp);
        }
    }
    cout<<output.size()<<endl;
    for(string i:output)
    {
        cout<<i<<endl;
    }
}