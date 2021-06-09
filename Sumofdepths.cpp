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

int calculateSum(BinaryTree*root)
{
    if(root==NULL)
    {
        return 0;
    }

    queue<BinaryTree*>q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    int k = 1;
    int count = 1;
    int total = 0;
    
    while(!q.empty())
    {
        BinaryTree*curr = q.front();
        q.pop();
        
        if(curr!=NULL)
        {
            if(level == k)
            {
                total = total + count;
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            if(level > 0)
            {
                count++;
                k++;
            }
            level++;
            
        }
        
    }
    
    return total;
}

void inorder(BinaryTree*root)
{
    BinaryTree*temp = root;

    cout<<root->value;
    inorder(root->left);
    inorder(root->right);
}
int main() {

    BinaryTree*root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    int count = 0;
    cout<<calculateSum(root);
    
    


}
