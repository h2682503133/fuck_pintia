#include <iostream>
using namespace std;
#include <stdlib.h> 
template <class T>
class Vector
{
    friend class ostream;
    template <class U>
    friend ostream& operator <<(ostream& os,const Vector<U> &v);
    private:
    T* p;
     int len;
    public:
    Vector()
    {
        len=0;
        p= new T;
    }
    Vector(Vector& v)
    {
        len=v.len;
        p= new T[len];
        for(int i=0;i<len;i++)
        {
            p[i]=v.p[i];
        }
    }
    ~Vector()
    {
        delete p;
    }
    int add(T a)
    {

		len+=1;
        p=(T*)realloc(p,len*sizeof(T));
        p[len-1]=a;
        return len-1;
    }
    void remove(int a)
    {
        for(int i=a;i<len-1;i++)
        {
            p[i]=p[i+1];
        }
        len-=1;
        p=(T*)realloc(p,len*sizeof(T));
    }
    int get_size()
    {
        return len;
    }
    T operator [] (int a)
    {
        return p[a];
    }
};
template <class U>
ostream& operator <<(ostream& os,const Vector<U> &v)
{
    os<< v.p[v.len-1];
    return os;
}
int main()
{
    Vector<int> vint;
    int n,m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        //    add() can inflate the vector automatically
        vint.add(i);    
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size()-1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}
