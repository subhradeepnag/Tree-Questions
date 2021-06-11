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

void solve(BST*tree, int &target,int &mini,int &l)
{
    if(tree == nullptr)
    {
        return;
    }
     if(mini > abs(target - (tree->value)))
     {
         mini = abs(target - (tree->value));
         l = tree->value;
     }
     
     solve(tree->left,target,mini,l);
     solve(tree->right,target,mini,l);
}

int findClosestToBST(BST*tree, int target)
{
    
    int mini = abs(target - (tree->value));
    int l = 0;
  
    solve(tree,target,mini,l);
    
    return l;
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
    cout<<findClosestToBST(root,12);
}
