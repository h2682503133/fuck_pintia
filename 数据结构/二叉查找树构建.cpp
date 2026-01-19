#include <string>
#include <iostream>
using namespace std;
struct node{
  int data;
  node *left=nullptr, *right=nullptr;

};
//本人因少写了这个“&”数据结构喜提-10
void add(node* &root, int data)
{
  if(root==nullptr) {root=new node;root->data=data;return;}
  else
  {
    if(data<root->data)add(root->left, data);
    else if(data>root->data)add(root->right, data);
  }
}
int main() 
{ 
  node *root=nullptr;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int data;
    cin>>data;
    add(root, data);
  }
}