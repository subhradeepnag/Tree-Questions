#include <bits/stdc++.h>
using namespace std;

class BST
{
    public:
        int value;
        BST*left;
        BST*right;

        BST(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

BST* insert(vector<int>arr,int start,int end)
{
    if(start>end)
    {
        return nullptr;
    }

    int mid = (start + end)/2;

    BST*root = new BST(arr[mid]);

    root->left = insert(arr,start,mid-1);

    root->right = insert(arr,mid+1,end);

    return root;
}

void display(BST* root)
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
    vector<int>arr{1,2,5,7,10,13,14,15,22};
    BST*root = insert(arr,0,arr.size()-1);
    display(root);

}