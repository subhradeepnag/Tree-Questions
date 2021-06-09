#include<bits/stdc++.h>
using namespace std;


//NODE STRUCTURE
struct node
{
    int key;
    struct node*left,*right;
};


//A UTILITY FUNCTION TO CREATE A NEW BST NODE
struct node*newNode(int item)
{
    struct node*temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;

}

//A UTILITY FUNCTION TO DO PREORDER TRAVERSAL 
void preorder(struct node*root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

