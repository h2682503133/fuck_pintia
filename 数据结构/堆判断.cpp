#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool test=false,test1,test2=true;
    queue<int> q;
    int temp1,temp2;
    cin>>temp1;
    q.push(temp1);
    for(int i=2;i<=n;i++)
    {
      if(i%2==0)
      {
        temp1=q.front();
        q.pop();
      }

      cin>>temp2;
      if(!test)
      {
        test1=temp1>temp2;
        if(temp1!=temp2)test=true;
      }
      else
      {
        if(test1)
        {
          if(temp1<temp2)
          {
            test2=false;
            break;
          }
        }
        else
        {
          if(temp1>temp2)
          {
            test2=false;
            break;
          }
        }
      }
      q.push(temp2);
    }
    if(test2&&test)
    {
        if(!test1)cout<<"这是小根堆";
        else cout<<"这是大根堆";
    }
    else cout<<"这不是堆";
}