#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    long int loc=0;
    map<int,int>count;
    vector<vector<int>> locs;
    for(int i=1;i<=N;i++)
    {
        int temp;
        cin>>temp;
        count[i]=temp;
        vector<int> temp2;
        locs.push_back(temp2);
    }
    while(count.size()>0)
    {
        int doub=1;
        int test;
        if(count.size()==1)
        {
            doub=2;
        }
        for(int j=0;j<N;j++)
        {
            if(count[j+1]>0&&test!=j+1&&count.size()==1)
            {
                loc--;
            }
            if(count[j+1]>0)
            {
                test=j+1;
            }
        }
        for(int i=0;i<10;i++)
        {
            
            
            for(int j=0;j<N;j++)
            {
                
                
                if(count[j+1]==0)
                {
                    
                    continue;
                }
                loc+=doub;

                locs[j].push_back(loc);
                

            }
        }
        for(int j=0;j<N;j++)
        {
            count[j+1]--;
            if(count[j+1]<=0)count.erase(j+1);
            
        }
    }
    for(int j=0;j<N;j++)
    {
        cout<<'#'<<j+1<<endl;
        for(unsigned long int i=0;i<locs[j].size();i++)
        {
            if((i+1)%10!=1)
                cout<<' ';
            cout<<locs[j][i];
            if((i+1)%10==0)
                cout<<endl;
        }
    }
}