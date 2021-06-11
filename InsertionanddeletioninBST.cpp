#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
    public:
        int value;
        BinaryTree*left;
        BinaryTree*right;

    BinaryTree(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTree*insert(BinaryTree*root,int val)
{
    if(root == nullptr)
    {
        return new BinaryTree(val);
    }

    if(val > root->value)
    {
        root->right = insert(root->right,val);
    }
    else
    {
        root->left = insert(root->left,val);
    }

    return root;
}

BinaryTree*findmin(BinaryTree*root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }

    return root;
}

BinaryTree*remove(BinaryTree*root,int data)
{
    if(root == nullptr)
    {
        return root;
    }

    else if(data < root->value)
    {
        root->left = remove(root->left,data);
    }
    else if (data > root->value)
    {
        root->right = remove(root->right,data);
    }
    else
    {
        // No left and Right Child
        if(root->left == NULL && root->right == NULL)
        {
            delete(root);
            root = NULL;
            return root;
        }

        else if (root->left == NULL)
        {
            BinaryTree*temp = root;
            root = root->right;
            delete (temp);
            return root;
        }
        else if (root->right == NULL)
        {
            BinaryTree*temp = root;
            root = root->left;
            delete (temp);
            return root;
        }
        else
        {
            BinaryTree*temp = findmin(root->right);
            root->value = temp->value;
            root->right = remove(root->right,temp->value);

            return root;
        }
    }
}

void display(BinaryTree*root)
{
    if(root == nullptr)
    {
        return;
    }

    display(root->left);
    cout<<root->value<<" ";
    display(root->right);
}
int main()
{
    BinaryTree*root = new BinaryTree(10);
    root->left = new BinaryTree(5);
    root->right = new BinaryTree(15);
    root->left->left = new BinaryTree(2);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(13);
    root->right->right = new BinaryTree(22);
    insert(root,12);
    remove(root,10);
    display(root);


}
