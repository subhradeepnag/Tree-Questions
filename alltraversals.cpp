#include <bits/stdc++.h>
using namespace std;

class BST
{
    public:
        int value;
        BST*left;
        BST*right;

        BST(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


void preorderTraversal(BST*tree,vector<int>&arr1)
{
    if(tree == nullptr)
    {
        return;
    }
    arr1.push_back(tree->value);
    preorderTraversal(tree->left,arr1);   
    preorderTraversal(tree->right);
}

void inorderTraversal(BST*tree,vector<int>&arr1)
{
    if(tree == nullptr)
    {
        return;
    }

    inorderTraversal(tree->left,arr1);
    arr1.push_back(tree->value);
    inorderTraversal(tree->right);
}

void postorderTraversal(BST*tree,vector<int>&arr1)
{
    if(tree == nullptr)
    {
        return;
    }

    postorderTraversal(tree->left,arr1);
    postorderTraversal(tree->right);
    arr1.push_back(tree->value);
}


int main()
{
    BST*root = new BST(10);
    root->left = new BST(5);
    root->right = new BST(15);
    root->left->left = new BST(2);
    root->left->right = new BST(5);
    root->right->left = new BST(13);
    root->right->right = new BST(22);
    root->left->left->left = new BST(1);
    root->right->left->right = new BST(14);

    vector<int>arr;
    preorderTraversal(root,arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    arr.clear();
    inorderTraversal(root,arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    arr.clear();
    postorderTraversal(root,arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}