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

void calculateSum(BinaryTree*root,int sum,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        sum+=root->value;
        ans.push_back(sum);
        return;
    }
    calculateSum(root->left,sum+root->value,ans);
    calculateSum(root->right,sum+root->value,ans);

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
    int sum = 0;
    vector<int>ans;
    calculateSum(root,sum,ans);
    for(int i:ans)
    {
        cout<<i<<" ";
    }
    


}
