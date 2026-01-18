#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
class HugeInteger
{
    
	
    public:
        friend ostream;
        friend ostream& operator << (ostream &os,const HugeInteger &a);
        HugeInteger operator + (HugeInteger &a)
        {
            return HugeInteger(add(this->num,a.num));
        }
        HugeInteger operator + (int a)
        {
            return HugeInteger(add(this->num,HugeInteger(a).num));
        }
        HugeInteger operator + (string a)
        {
            return HugeInteger(add(this->num,HugeInteger(a).num));
        }
    
        HugeInteger()
        {
            num = "0";

        }
        HugeInteger(int a)
        {
            string temp = to_string(a);
            num=temp;
        }
        HugeInteger(string a)
        {
            num=a;
        }
        HugeInteger(HugeInteger &a)
        {
            num=a.num;
        }
        string add(string a,string b);
    private:
        string num;
    
};
string HugeInteger::add(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int step=0;
    int lena=size(a),lenb=size(b);
    int len=lena>lenb?lena:lenb;
    char c[len+2]="";
    int i=0;
    for(;i<len;i++)
    {
        int ia,ib;
        if(i>=lena)ia=0;
        else ia=a[i]-'0';
        if(i>=lenb)ib=0;
        else ib=b[i]-'0';
        int temp=ia+ib+step;
        if(temp<=9)
        {
            c[i]=temp+'0';
            step=0;
        }
        else
        {
            c[i]=temp-10+'0';
            step=1;
        }
    }
    if(step==1)
    {
        c[i]='1';
        i++;
    }
    string d(c);
    reverse(d.begin(),d.end());
    return d;
}
ostream& operator << (ostream &os,const HugeInteger &a)
{
	os<<a.num;
    return os;
}
int main()
{
   HugeInteger n1( 7654321 );
   HugeInteger n2( 7891234 );
   HugeInteger n3( "99999999999999999999999999999" );
   HugeInteger n4( "1" );
   HugeInteger n5;
   cout << "n1 is " << n1 << "\nn2 is " << n2
      << "\nn3 is " << n3 << "\nn4 is " << n4
      << "\nn5 is " << n5 << "\n\n";
   n5 = n1 + n2;
   cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
   cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
   n5 = n1 + 9;
   cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
   n5 = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << n5 << endl;
    
    return 0;
}
