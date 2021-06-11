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


int calculateHeight(BinaryTree*root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(calculateHeight(root->left),calculateHeight(root->right)) + 1;
}
int calculateDiameter(BinaryTree*root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lheight = calculateHeight(root->left);
    int rheight = calculateHeight(root->right);

    int currDiameter = lheight + rheight + 1;

    int ldiameter = calculateDiameter(root->left);
    int rdiameter = calculateDiameter(root->right);


    return max(currDiameter,max(ldiameter,rdiameter));
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
    cout<<calculateDiameter(root);
}