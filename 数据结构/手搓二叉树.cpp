#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;
class note {
    public:
    char value;
    note *before;
    note *left;
    note *right;
    note(int value,note *left=nullptr,note *right=nullptr) {
        this->value = value;
        this->before = nullptr;
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
note* findMax(note* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}
note* findMin(note* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

note* deleteNode(note* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left != nullptr) {
            note* maxNode = findMax(root->left);
            root->value = maxNode->value; // 直接赋值 int 值
            root->left = deleteNode(root->left, maxNode->value);
        }
        else {
            note* minNode = findMin(root->right);
            root->value = minNode->value; // 直接赋值 int 值
            root->right = deleteNode(root->right, minNode->value);
        }
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    note* root = nullptr;
    for (int i = 0; i < N; i++) {
        int temp;
        cin>>temp;
        root = buildBST(root, temp);
    }
    int K;
    cin>>K;
    for (int i = 0; i < K; ++i) {
        int temp;
        cin >> temp;
        root = deleteNode(root, key);
    }
    queue<n*> temp1;
    temp1
    while()
    for (int i = 0; i < res.size(); ++i) 
    {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    return 0;
}