#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node*left,*right;
};

Node*newNode(int num)
{
    Node*temp = new Node;
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}
Node*insert(Node*root,int key)
{
    if(root == NULL)
    {
        return newNode(key);
    }
    if(root->data > key)
    {
        root->left = insert(root->left,key);
    }
    else
    {
        root->right = insert(root->right,key);
    }

    return root;
    
}

void seqExistUtil(Node*ptr,int seq[],int &index)
{
    if(ptr == NULL)
    {
        return;
    }
    //We traverse left subtree first in Inorder
    seqExistUtil(ptr->left,seq,index);

    //If current node matches with se[index] then move forward in sub-sequence

    if(ptr->data == seq[index])
    {
        index++;
    }

    seqExistUtil(ptr->right,seq,index);


}
bool seqExist(Node*root,int seq[],int n)
{
    int index = 0;
    //Do an inorder traversal and find if all element of seq[] were present
    seqExistUtil(root,seq,index);
    return (index == n);

}

int main()
{
    struct Node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 10); 
    root = insert(root, 3); 
    root = insert(root, 6); 
    root = insert(root, 1); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 14); 
    root = insert(root, 13); 
  
    int seq[] = {4, 6, 8, 14}; 
    int n = sizeof(seq)/sizeof(seq[0]); 
  
    seqExist(root, seq, n)? cout << "Yes" : 
                            cout << "No"; 
  
    return 0;   
}