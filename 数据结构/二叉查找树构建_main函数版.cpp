#include <string>
#include <iostream>
using namespace std;
struct node{
  int data=-1;
  node *left=nullptr, *right=nullptr;

};
int main() 
{ 
  int n;
  cin>>n;
  int value;
  cin>>value;
  node *root=new node;
  root->data=value;
  //用一个指向指针的指针 可以修改left和right指向的地址从而new新空间
  node* *temp=&root;
  for(int i=1;i<n;i++)
  {
    cin>>value;
    temp=&root;
    while((*temp)->data!=-1)
    {
      if(value<(*temp)->data)temp=&((*temp)->left);
      else temp=&((*temp)->right);
      if(*temp==nullptr)*temp=new node;
    }
    (*temp)->data=value;
  }
}