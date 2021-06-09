#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node*left;
        node*right;
};

node*newNode(int data)
{
    node*temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node*sortedArray(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    node*root = newNode(arr[mid]);
    root->left = sortedArray(arr,start,mid-1);
    root->right = sortedArray(arr,mid+1,end);

    return root;
}

node*constructTree(int arr[],int n)
{
    sort(arr,arr+n);

    node*root = sortedArray(arr,0,n-1);
    
    return root;
}

void printInorder(node*Node)
{
    if(Node==NULL)
    {
        return;
    }

    printInorder(Node->left);
    cout<<Node->data<<" ";
    printInorder(Node->right);
}
int main()
{
    int pre[] = {10,5,1,7,40,50};
    int size = sizeof(pre)/sizeof(pre[0]);
    node*root = constructTree(pre,size);
    cout<<"Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}

