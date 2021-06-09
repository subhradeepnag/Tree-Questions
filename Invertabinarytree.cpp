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

BinaryTree*invert(BinaryTree*root)
{
    if(root==NULL)
    {
        return NULL;
    }

   BinaryTree*left = invert(root->left);
   BinaryTree*right = invert(root->right);
   root->left = right;
   root->right = left;
   
   return root;

}

void preorder(BinaryTree*root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    BinaryTree*root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    BinaryTree*temp = invert(root);
    preorder(temp);
    


}
