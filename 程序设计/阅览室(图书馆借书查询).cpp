#include <string>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int days;
    cin>>days;
    for(int i=0;i<days;i++)
    {
        int count=0,totaltimes=0;
        set<int> books;
        map<int,int> time;
        int key=0;
        cin>>key;
        int hour,min;
        char command;
        string input;
        while(key!=0)
        {

            cin>>command;
            
            cin>>input;
            sscanf(input.c_str(),"%d:%d",&hour,&min);
            if(command=='S')
            {
                time[key]=min+60*hour;
                books.insert(key);
            }
            else if(command=='E'&&time.find(key)!=time.end())//此处必须用find和后面删除的形式，我也不知道为什么
            {
                totaltimes+=min+60*hour-time[key];
                time.erase(key);
                books.erase(key);
                count++;
            }
            cin>>key;
        }
        cin>>command>>input;
        cout<<count<<' '<<(count==(int)0?0:int(totaltimes/(float)count+0.5))<<endl;
    }
}