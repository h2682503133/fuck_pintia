#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Student{
    private:
    unsigned long id;
    unsigned int a;
    unsigned int b;
    public:
    Student(int id,int a,int b)
    {
        this->id=id;
        this->a=a;
        this->b=b;
    }
    unsigned long getid()
    {
        return id;
    }
    friend bool test(Student before,Student next);//before是否该在next之前
    bool test(Student other)
    {
        if(a==other.a&&b==other.b)return id<other.id;
        else return a==other.a?b>other.b:a>other.a;
    }
};
bool test(Student before,Student other)
{
    if(before.a==other.a&&before.b==other.b)return before.id<other.id;
    else return before.a==other.a?before.b>other.b:before.a>other.a;
}
int main()
{
    int n;
    cin>>n;
    vector<Student> students;
    for(int i=0;i<n;i++)
    {
        unsigned long id;
        unsigned int a;
        unsigned int b;
        cin>>id>>a>>b;
        students.push_back(*(new Student(id,a,b)));
    }/*
    for(int i=1;i<n;i++)
    {
        Student* temp =students[i];
        int flag=1;
        for(int j=i-1;j>=0;j--)
        {
            if(!(temp->test(*students[j])))
            {
                students[j+1]=temp;
                flag=0;
                break;
            }
            students[j+1]=students[j];
        }
        if(flag)students[0]=temp;
    }*/
    sort(students.begin(),students.end(),test);
    for (int i=0;i<n;i++)
    {
        cout<<students[i].getid()<<endl;
    }
}