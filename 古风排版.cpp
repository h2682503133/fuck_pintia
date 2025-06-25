#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    string words;
    getline(cin,words);
    while(words.size()%N!=0)
    {
        words+=string(" ");
    }
    vector<string> order;
    long unsigned int i=0;
    for(;i<words.size()/N;i++)
    {
        order.push_back(words.substr(i*N,N));
    }
    reverse(order.begin(),order.end());
    for(int j=0;j<N;j++)
    {
        for(long unsigned int i=0;i<order.size();i++)
        {
            cout<<order[i][j];
        }
        cout<<endl;
    }
}