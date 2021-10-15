#include <iostream>
#include <stdio.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode* create_bst(int arr[],int low=0,int high=7){
    int mid = low + (high-low)/2;
    if(low<=high){
        return NULL;
    }
    TreeNode* root = new TreeNode(arr[mid]);
    root->left =  create_bst(arr,low,mid-1);
    root->right = create_bst(arr,mid+1,high);
    return root;
}

int main(){
    
    return 0;
}
