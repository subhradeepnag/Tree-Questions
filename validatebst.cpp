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

bool check(BST*tree,BST*min = NULL,BST*max = NULL)
{
    if(tree == NULL)
    {
        return true;
    }

    if(min!=NULL && tree->value < min->value)
    {
        return false;
    }
    if(max!=NULL && tree->value >= max->value)
    {
        return false;
    }

    bool leftValid = check(tree->left,min,tree);
    bool rightValid = check(tree->right,tree,max);

    return leftValid and rightValid;
}

bool validBST(BST*tree)
{
    if(check(tree,NULL,NULL) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    cout<<validBST(root);
}
