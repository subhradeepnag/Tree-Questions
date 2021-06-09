#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calheight(Node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return max(calheight(root->left),calheight(root->right)) + 1;
}

int diameter(Node*root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    int maxheight = lheight + rheight + 1;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(maxheight,max(ldiameter,rdiameter));
}

int optimisedCode(Node*root,int *height)
{
    if(root==NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0,rh = 0;
    int ldiameter = optimisedCode(root->left,&lh);
    int rdiameter = optimisedCode(root->right,&rh);

    int currdiameter = ldiameter + rdiameter + 1;

    *height = max(lh,rh) + 1;

    return max(currdiameter,max(ldiameter,rdiameter));
}

int main()
{
    struct Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<diameter(root,&height);
    return 0;
}