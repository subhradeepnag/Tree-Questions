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

int search(vector<int>inorder,int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }

    return -1;
}

Node*buildTree(vector<int>preorder,vector<int>inorder,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    Node*node = new Node(curr);

    if(start==end)
    {
        return node;
    }

    int pos = search(inorder,start,end,curr);

    node->left = buildTree(preorder,inorder,start,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,end);

    return node;
}

void Printinorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    Printinorder(root->left);
    cout<<root->data<<" ";
    Printinorder(root->right);
}

int main()
{
    vector<int>preorder{1, 2, 4, 3, 5};
    vector<int>inorder{4, 2, 1, 3, 5};
    Node* root = buildTree(preorder,inorder,0,preorder.size()-1);
    Printinorder(root);
}