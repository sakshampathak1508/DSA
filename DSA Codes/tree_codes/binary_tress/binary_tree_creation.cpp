#include <iostream>
#include <stdio.h>
#include <queue>
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

TreeNode *take_input()
{
    int data;
    cout << "Enter node data ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(data);
    TreeNode *left = take_input();
    TreeNode *right = take_input();
    root->left = left;
    root->right = right;
    return root;
}

TreeNode *take_level_input()
{
    int data;
    queue<TreeNode *> q;
    cout << "Enter Root Node data ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(data);
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode *front = q.front();
        q.pop();
        cout << "Enter the left child of " << front->data << ": ";
        cin >> data;
        if (data != -1)
        {
            TreeNode *left = new TreeNode(data);
            front->left = left;
            q.push(left);
        }
        cout << "Enter the right child of " << front->data << ": ";
        cin >> data;
        if (data != -1)
        {
            TreeNode *right = new TreeNode(data);
            front->right = right;
            q.push(right);
        }
    }
    return root;
}

void print_tree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left)
    {
        cout << "L: " << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R: " << root->right->data << " ";
    }
    cout << endl;
    print_tree(root->left);
    print_tree(root->right);
}

void level_order_trav(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode *front = q.front();
        cout << front->data << " ";
        q.pop();
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
}

int num_nodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + num_nodes(root->left) + num_nodes(root->right);
}

int main()
{
    TreeNode *root = take_level_input();
    level_order_trav(root);
    cout << "Number of nodes are " << num_nodes(root);
    return 0;
}
