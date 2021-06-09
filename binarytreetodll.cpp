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

void solve(BinaryTree*root,BinaryTree*&head,BinaryTree*&prev,int &flag)
{
    if(root == nullptr)
    {
        return 0;
    }

    solve(root->left,head,prev,flag);

    if(flag == 0)
    {
        flag = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    solve(root->right,head,prev,flag);
}

BinaryTree*flattenBinaryTree(BinaryTree*root)
{
    BinaryTree*head = NULL;
    BinaryTree*prev = NULL;
    int flag = 0;
    solve(root,head,prev,flag); 
    return head;
}

void display(Node*root)
{
    Node*temp = head;

    while(temp!=NULL)
    {
        cout<<temp->val;

        temp = temp->right;
    }
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

    root = flattenBinaryTree(root);
    display(root);
    
}