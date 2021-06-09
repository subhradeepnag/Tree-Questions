#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left,*right;
};

struct Node* newNode(int key)
{
    struct Node*temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(struct Node*temp)
{
    if(!temp)
    {
        return;
    }
    inorder(temp->left);
    cout<<temp->key<<" ";
    inorder(temp->right);

}


void deletDeepest(struct Node*root,struct Node*d_node)
{
    queue<Node*>q;
    q.push(root);

    struct Node*temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp == d_node)
        {
            temp = NULL;
            delete(d_node);
            return;
        }

        if(temp->right)
        {
            if(temp->right == d_node)
            {
                temp->right == NULL;
                delete(d_node);
                return;

            }
            else
            {
                q.push(temp->right);
            }
            
        }

        if(temp->left)
        {
            if(temp->left == d_node)
            {
                temp->left =NULL;
                delete(d_node);
                return;
            }
            else
            {
                q.push(temp->left);
            }
            
        }
    }
}

Node*deletion(struct Node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        if(root->key == key)
        {
            return NULL;
        }
        else
        {
            return root;
        }
        
    }

    queue<Node*>q;
    q.push(root);

    struct Node*temp;
    struct Node*key_node = NULL;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->key == key)
        {
            key_node = temp;
        }
        if(temp->left)
        {
            q.push(temp->right);
        }

    }

    if(key_node!=NULL)
    {
        int x = temp->key;
        deletDeepest(root,temp);
        key_node->key = x;
    }

    return root;
}

int main()
{

}