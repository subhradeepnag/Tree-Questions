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

int search(vector<int>&inorder,int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
BST*ReconstructBST(vector<int>&preorder,vector<int>&inorder,int start,int end,int &index)
{
    if(start>end)
    {
        return NULL;
    }

    int curr = preorder[index];
    index++;
    BST*node = new BST(curr);
    if(start == end)
    {
        return node;
    }

    int pos = search(inorder,start,end,curr);
    node->left = ReconstructBST(preorder,inorder,start,pos-1,index);
    node->right = ReconstructBST(preorder,inorder,pos+1,end,index);

    return node;
}

void display(BST*root)
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
    vector<int>preorder{10,4,2,1,5,17,18,19};
    vector<int>inorder{10,4,2,1,5,17,18,19};
    sort(inorder.begin(),inorder.end());
    int n = preorder.size();
    int index = 0;
    BST*temp = ReconstructBST(preorder,inorder,0,n-1,index);
    display(temp);
}