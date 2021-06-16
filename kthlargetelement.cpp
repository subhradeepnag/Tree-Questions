#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
    public:
        int value;
        BinaryTree*left;
        BinaryTree*right;

    BinaryTree(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void kthLargestUtil(BinaryTree*root,int &k,int &count)
{
    if(root == nullptr || count>=k)
    {
        return;
    }

    kthLargestUtil(root->right,k,count);
    count++;

    if(count == k)
    {
        cout<<root->key<<" ";
        return;
    }
    kthLargestUtil(root->left,k,count);
}

void kthlargest(BinaryTree*root,int k)
{
    int count = 0;
    solve(root,k,count);
}

int main()
{
    BinaryTree*root = new BinaryTree(10);
    root->left = new BinaryTree(5);
    root->right = new BinaryTree(15);
    root->left->left = new BinaryTree(2);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(13);
    root->right->right = new BinaryTree(22);
    int k =3;
    kthlargest(root,k);


}