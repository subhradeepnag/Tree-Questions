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

bool isSame(BST*root1,BST*root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }

    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

   
    bool cond1 = root1->value == root2->value;
    bool cond2 = isSame(root1->left,root2->left);
    bool cond3 = isSame(root1->right,root2->right);
        
    return cond1 && cond2 && cond3;
}

int main()
{
    BST*root1 = new BST(1);
    root1->left = new BST(2);
    root1->right = new BST(3);

    BST*root2 = new BST(1);
    root2->left = new BST(2);
    root2->right = new BST(6);

    if(isSame(root1,root2) == true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }


}