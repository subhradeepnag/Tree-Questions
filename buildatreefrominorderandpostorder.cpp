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

int search(vector<int>inorder,int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

Node*buildtree(vector<int>postorder,vector<int>inorder,int start,int end)
{
    static int idx = postorder.size()-1;

    if(start>end)
    {
        return NULL;
    }
    
    int val = postorder[idx];
    idx--;

    Node*curr = new Node(val);

    if(start == end)
    {
        return curr;
    }
    int pos = search(inorder,start,end,val);

    curr->right = buildtree(postorder,inorder,pos+1,end);
    curr->left = buildtree(postorder,inorder,start,pos-1);

    return curr;
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
    vector<int>postorder{4,2,5,3,1};
    vector<int>inorder{4,2,1,5,3};
    Node*root = buildtree(postorder,inorder,0,postorder.size()-1);
    Printinorder(root);

    
}