#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node*newnode(int data)
{
    struct node*Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
struct node*insert(struct node*node,int data)
{
    if(node==NULL)
    {
        return (newnode(data));
    }
    else
    {
        if(data<=node->data)
        {
            node->left = insert(node->left,data);
        }
        else
        {
            node->right = insert(node->right,data);
        }

        return node;
        
    }   
}
int maxValue(struct node*node)
{
    struct node*current = node;
    while(current->right!=NULL)
    {
        current = current->right;
    }

    return (current->data);
}

int minValue(struct node*node)
{
    struct node*current = node;
    while(current->left!=nullptr)
    {
        current = current->left;
    }

    return (current->data);
}

int main()
{
    struct node*root = NULL;
    root = insert(root,4);
    insert(root,2);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    insert(root,5);

    cout << "Maximum value in BST is " << maxValue(root)<<endl; 
    cout << "Minimum value in BST is " << minValue(root); 
}