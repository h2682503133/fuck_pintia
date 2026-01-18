#include <iostream>
using namespace std;
long long  c(int* nums,int l,int m,int r)
{
    int i=l,j=m+1;
    long long count=0;
    int temp[r-l+1]={0};
    for(int k=0;k<r-l+1;k++)
    {
        if(j>r||(i<=m&&nums[i]<=nums[j]))
        {
            temp[k]=nums[i];
            i++;
        }
        else if(i>m||(j<=r&&nums[i]>=nums[j]))
        {
            temp[k]=nums[j];
            count+=j-l-k;
            j++;
        }
    }
    for(int i=0;i<=r-l;i++)
    {
        nums[l+i]=temp[i];
    }
    return count;
}
int main()
{
    int n;
    long long count=0;;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int length=1;
    while(length<n)
    {
        int l=0;
        int m=l+length-1;
        int r=l+2*length-1;
        while(m<n-1)
        {
            count+=c(nums,l,m,r);
            l+=2*length;
            m+=2*length;
            r+=2*length;
            r=r>n-1?n-1:r;
        }
        length*=2;
    }
    cout<<"count = "<<count<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<' ';
    }
}