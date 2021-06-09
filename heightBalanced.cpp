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

int height(BinaryTree*root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh,rh) + 1;
}

bool isBalanced(BinaryTree*root)
{
    if(root == NULL)
    {
        return true;
    }

    if(isBalanced(root->left) == false)
    {
        return false;
    }
    if(isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main() {

    BinaryTree*root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(8);
    // root->right->right = new BinaryTree(7);
    // root->left->left->left = new BinaryTree(8);
    // root->left->left->right = new BinaryTree(9);
    if(check(root) == true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
}