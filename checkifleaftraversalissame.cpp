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

void recursive1(vector<int>tree1,BinaryTree*root1)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        tree1.push_back(root->val);
    }

    recursive(tree1,root1->left);
    recursive(tree1,root1->right);
}
bool compareLeafTraversal(BinaryTree*root1,BinaryTree*root2)
{
    vector<int>tree1;
    vector<int>tree2;

    recursive1(tree1,root1);
    recursive2(tree2,root2);

}

int main()
{
    BinaryTree*root1 = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->left->right->left = new BinaryTree(7);
    root->left->right->right = new BinaryTree(8);

    BinaryTree*root2 = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(7);
    root->right->right = new BinaryTree(5);
    root->right->right->left = new BinaryTree(8);
    root->right->right->right = new BinaryTree(6);

    compareLeafTraversal(root1,root2);
}