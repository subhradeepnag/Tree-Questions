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

BinaryTree*leftMostNode(BinaryTree*node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}
BinaryTree*rightMostNode(BinaryTree*node)
{
    while (node != NULL && node->right != NULL)
        node = node->left;
    return node;
}

BinaryTree*findInorderRec(BinaryTree*root,BinaryTree*node)
{
    if(root == NULL)
    {
        return NULL;
    }

    BinaryTree*temp;
    if(root == node || temp = findInorderRec(root->left,node) || temp = findInorderRec(root->right,node))
    {
        if(temp!=NULL)
        {
            if(root->left == temp)
            {
                return root->data;
            }
        }

        return root;
    }
}

BinaryTree*findSuccesor(BinaryTree*root,BinaryTree*node)
{
    if(root==NULL || node == NULL)
    {
        return NULL;
    }

    if(node->right!=NULL)
    {
        return leftMostNode(node->right);
    }
    else
    {
        if(node->right==NULL)
        {
            BinaryTree*rightmost = rightMostNode(root);

            // IF NODE IS THE RIGHT MOST CHILD
            if(rightmost == node)
            {
                return NULL;
            }
            else
            {
                return findInorderRec(root,node);
            }
        }
    }
}

int main() {

    BinaryTree*root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    // root->right->right = new BinaryTree(7);
    // root->left->left->left = new BinaryTree(8);
    // root->left->left->right = new BinaryTree(9);
    cout<<findSucessor(root,root->left->right);
}