#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;
};

node*newNode(int data)
{
    node*Node = new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

node*insert(node*Node,int data)
{
    if(Node == NULL)
    {
        return(newNode(data));
    }
    else
    {
        if(data<=Node->data)
        {
            Node->left = insert(Node->left,data);
        }
        else
        {
            Node->right = insert(Node->right,data);
        }
        return Node; 
    }
    
}

int minValue(node*Node)
{
    node*current = Node;

    while(current->left!=NULL)
    {
        current = current->left;
    }

    return (current->data);
}

int main()
{
    node*root = NULL;
    root = insert(root,4);
    insert(root,2);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    insert(root,5);

    cout<<"Minimum value in bst is "<<minValue(root);
    getchar();
    return 0;
}