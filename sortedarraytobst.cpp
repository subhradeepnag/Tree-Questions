#include<bits/stdc++.h>
using namespace std;

class Tnode
{
    public:
        int data;
        Tnode*left;
        Tnode*right;
};

Tnode* newNode(int data)
{
    Tnode*node = new Tnode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Tnode*sortedArray(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    int mid = (start+end)/2;
    TNode*root = newNode(arr[mid]);
    root->left = sortedArray(arr,start,mid-1);
    root->right = sortedArray(arr,mid+1,end);
    return root;

}

//A UTILITY FUNCTION TO PRINT PREORDER TRAVERSAL OF BST

void preOrder(Tnode*node)
{
    if(node==NULL)
    {
        return;
    }

    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    //CONVERT LIST TO BST

    Tnode*root = sortedArray(arr,0,n-1);
    cout<<"PreOrder Traversal to constructed BST \n";
    preOrder(root);

    return 0;
}