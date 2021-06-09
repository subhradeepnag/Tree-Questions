#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node*left;
        node*right;

};

node*newnode(int data)
{
    node*Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node); 
}

void printInorder(node*node)
{
    if(node == NULL)
    {
        return;
    }

    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

node*sortedArraytoBST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    node*root = newnode(arr[mid]);
    root->left = sortedArraytoBST(arr,start,mid-1);
    root->right = sortedArraytoBST(arr,mid+1,end);

    return root;
}
int main()
{

}