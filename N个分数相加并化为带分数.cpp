#include <iostream>
using namespace std;
long gcd(long a, long b) 
{
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
pair<long,long> conclude(pair<long,long> a,pair<long,long> b)
{
    long z,m;
    long gcdt=gcd(a.second,b.second);
    m=a.second/gcdt*b.second;
    z=a.first*(b.second/gcdt)+b.first*(a.second/gcdt);
    gcdt=gcd(m,z);
    return pair(z/gcdt,m/gcdt);
}
int main ()
{
    int N;
    cin>>N;
    pair<long,long> sum;
    char temp;
    cin>>sum.first>>temp>>sum.second;
    for(int i=1;i<N;i++)
    {
        pair<long,long> next;
        cin>>next.first>>temp>>next.second;
        sum=conclude(sum,next);
    }
    int z=sum.first/sum.second;
    sum.first=sum.first%sum.second;
    if(z !=0)
        cout<<z;
    if(sum.first !=0&&z !=0)
        cout<<' ';
    if(sum.first !=0)
        cout<<sum.first<<'/'<<sum.second<<endl;
    if(sum.first ==0&&z ==0)
        cout<<0;
}