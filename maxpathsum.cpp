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

int maxPathSumUtil(BinaryTree*root,int &res)
{
    if(root == nullptr)
    {
        return 0;
    }

    int left = maxPathSumUtil(root->left,res);
    int right = maxPathSumUtil(root->right,res);

    int temp = max(max(left,right)+root->value,root->value);

    int ans = max(temp,left+right+root->value);

    res = max(res,ans);

    return temp;
}
int maxPathSum(BinaryTree*tree)
{
    int res = INT_MIN;

    maxPathSumUtil(tree,res);
    
    return res;
}

int main() {

    BinaryTree*root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    // root->left->right->right = new BinaryTree(8);
    // root->right->right = new BinaryTree(7);
    // root->left->left->left = new BinaryTree(8);
    // root->left->left->right = new BinaryTree(9);
    cout<<maxPathSum(root);
}