#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(struct Node*root)
{
    stack<Node*>stk;
    Node*curr = root;

    while(curr!=NULL || stk.empty()==false)
    {
        if(curr!=NULL)
        {
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stk.top();
            stk.pop();
            cout<<curr->data<<" "<<flush;
            curr = curr->right;
        }
        
    }
}

int main()
{
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrder(root); 
    return 0; 
}