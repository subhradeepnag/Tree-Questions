#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node*left;
    struct Node*right;
};

struct Node*newNode(int key)
{
    Node*node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void addSmallerUtil(struct Node*root , int*sum)
{
    if(root==NULL)
    {
        return;
    }

    addSmallerUtil(root->left,sum);
    *sum = *sum + root->key;
    root->key = *sum;
    addSmallerUtil(root->right,sum);
}

void addSmaller(struct Node*root)
{
    int sum = 0;
    addSmallerUtil(root,&sum);
}

void printInorder(struct Node*node)
{
    if(node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout<<node->key<<" ";
    printInorder(node->right);
}

int main()
{
    Node* root = newNode(9); 
    root->left = newNode(6); 
    root->right = newNode(15); 
  
    printf(" Original BST\n"); 
    printInorder(root); 
  
    addSmaller(root); 
  
    printf("\n BST To Binary Tree\n"); 
    printInorder(root); 
  
    return 0; 
}