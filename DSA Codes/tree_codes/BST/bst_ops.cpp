#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode(){
            delete left;
            delete right;
        }
};

TreeNode* take_input(){
    int data;
    cout<<"enter root data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        int data;
        cout<<"enter the left child of "<<front->data<<": ";
        cin>>data;
        if(data!=-1){
            TreeNode* left_child = new TreeNode(data);
            front->left = left_child;
            q.push(left_child);
        }
        cout<<"enter the right child of "<<front->data<<": ";
        cin>>data;
        if(data!=-1){
            TreeNode* right_child = new TreeNode(data);
            front->right = right_child;
            q.push(right_child);
        }
    }
    return root;
}

void inorder_it(TreeNode* root){
    stack<TreeNode*> s;
    TreeNode* temp = root;
    while(temp!=NULL or s.size()!=0){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout<<temp->data<<", ";
        temp = temp->right;
    }
    cout<<endl;
}

bool search(TreeNode* root,int key){
    while(root!=NULL){
        if(root->data==key){
            return true;
        }
        else if(root->data<key){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return false;
}

void insert(TreeNode* root,int key){
    TreeNode* temp = root;
    TreeNode *prev = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return;
        }
        else if (temp->data < key)
        {
            prev = temp;
            temp = temp->right;
        }
        else
        {   
            prev = temp;
            temp = temp->left;
        }
    }
    TreeNode* new_node = new TreeNode(key);
    if(key<prev->data){
        prev->left = new_node;
    }
    else{
        prev->right = new_node;
    }
}

TreeNode* inorder_pre(TreeNode* root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

TreeNode* _delete(TreeNode* temp,int key){
    TreeNode* ptr;
    if(temp==NULL){
        return NULL;
    }
    if(temp->left==NULL and temp->right==NULL){
        delete temp;
        return NULL;
    }
    if(temp->data<key){
        temp->right = _delete(temp->right,key);
    }
    else if(temp->data > key){
        temp->left = _delete(temp->left, key);
    }
    else{
        ptr = inorder_pre(temp);
        temp->data = ptr->data;
        temp->left = _delete(temp->left,ptr->data);
    }
    return temp;
}

int main(){
    TreeNode* root = take_input();
    inorder_it(root);
    insert(root,9);
    inorder_it(root);
    root = _delete(root,6);
    inorder_it(root);
    return 0;
}
