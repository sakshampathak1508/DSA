#include <iostream>
#include <stdio.h>
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

void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<", ";
    preorder(root->left);
    preorder(root->right);
}

void preorder_it(TreeNode* root){
    TreeNode* temp = root;
    if(root==NULL){
        return;
    }
    stack<TreeNode*> s;
    s.push(temp);
    while(s.size()!=0){
        temp = s.top();
        s.pop();
        cout<<temp->data<<", ";
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

void inorder_it(TreeNode *root){
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
}

void postorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<", ";
}

void postorder_it(TreeNode* root){
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    TreeNode* temp = root;
    while(s1.size()!=0){
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(s2.size()!=0){
        cout<<s2.top()->data<<", ";
        s2.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // preorder(root);
    // cout << endl;
    // preorder_it(root);
    // cout << endl;
    postorder(root);
    cout<<endl;
    postorder_it(root);
    cout<<endl;
    // inorder(root);
    // cout<<endl;
    // inorder_it(root);
    // cout<<endl;

    return 0;
}
