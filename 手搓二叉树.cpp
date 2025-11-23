#include <iostream>
#include <stack>
#include <string>
using namespace std;
class note {
    public:
    char value;
    note *before;
    note *left;
    note *right;
    note(int value,note *left=NULL,note *right=NULL) {
        this->value = value;
        this->before = NULL;
        this->left = left;
        this->right = right;
        if(left)
        left->before = this;
        if(right)
        right->before = this;
    }
    ~note() {
        if(left)
        delete left;
        if(right)
        delete right;
    }
};
note* made(const std::string& s, int& index) {
    if (index >= (int)s.size() || s[index] == '#') {
        if (index < (int)s.size()) {
            index++;
        }
        return nullptr;
    }
    char current_value = s[index];
    index++;
    note* left_child = made(s, index);
    note* right_child = made(s, index);
    return new note(current_value, left_child, right_child);
}
void preOrder(note* n) {
    if (n == nullptr) {
        return;
    }
    cout << n->value;
    preOrder(n->left);
    preOrder(n->right);
}
void inOrder(note *n){
    if (n == nullptr) {
        return;
    }
    inOrder(n->left);
    cout << n->value;
    inOrder(n->right);
}
void postOrder(note *n){
    if (n == nullptr) {
        return;
    }
    postOrder(n->left);
    postOrder(n->right);
    cout << n->value;
}
int count(note *n){
    if (n==nullptr)return 0;
    else if(!n->left&!n->right)return 1;
    else return count(n->left)+count(n->right);
}
int main()
{
    string c;
    cin>>c;
    int start=0;
    note *n = made(c,start);
    if(count(n)>0)
    {
        preOrder(n);
        cout<<endl;
        inOrder(n);
        cout<<endl;
        postOrder(n);
        cout<<endl;
    }
    cout<<count(n)<<endl;
}