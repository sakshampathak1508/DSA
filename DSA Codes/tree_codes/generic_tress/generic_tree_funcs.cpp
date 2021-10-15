#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class TreeNode{
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data){
            this->data = data;
        }

};

TreeNode* take_input(){
    int data,n;
    cout<<"Enter root data: ";
    cin>>data;
    TreeNode* root = new TreeNode(data);
    cout<<"Enter the number of children of "<<data;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode* child = take_input();
        root->children.push_back(child);
    }
    return root;
}

TreeNode* take_level_input(){
    queue<TreeNode*> q;
    int data,n;
    cout<<"Enter root data: ";
    cin>>data;
    TreeNode* root = new TreeNode(data);
    q.push(root);
    while(q.size()!=0){
        TreeNode* front = q.front();
        q.pop();
        cout<<"enter the number of children for "<<front->data<<": ";
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter "<<i+1<<" child of "<<front->data<<": ";
            cin>>data;
            TreeNode* child = new TreeNode(data);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void print_tree(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": "; 
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print_tree(root->children[i]);
    }

}

int count_nodes(TreeNode*root){
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += count_nodes(root->children[i]);
    }
    return ans;
}


int leaf_nodes(TreeNode* root){
    int ans = 0;
    if(root->children.size()==0){
        return 1;    
    }
    for(int i=0;i<root->children.size();i++){
        ans+= leaf_nodes(root->children[i]);  
    }
    return ans;
}

int main(){
    TreeNode* root = take_level_input();
    // TreeNode* root = new TreeNode(1);
    // TreeNode* child1 = new TreeNode(2);
    // TreeNode* child2 = new TreeNode(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    print_tree(root);
    // cout<<"Total number of nodes are: "<<count_nodes(root);
    cout<<"Total number of leaf nodes are: "<<leaf_nodes(root);
    return 0;
}
