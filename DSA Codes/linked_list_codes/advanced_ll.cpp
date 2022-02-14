#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
};

node *create(node *head)
{
    int n, data;
    cout << "Enter the number of nodes init: ";
    cin >> n;
    if (head == NULL)
    {
        head = new node();
        cout << "Enter node data: ";
        cin >> data;
        head->data = data;
        head->next = NULL;
        n--;
    }
    node *p = head;
    while (n--)
    {
        node *ptr = new node();
        cout << "Enter node data: ";
        cin >> data;
        ptr->data = data;
        ptr->next = NULL;
        p->next = ptr;
        p = ptr;
    }
    return head;
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << endl;
}

node *list_mid(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge_sorted_ll(node *l1, node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    node *p = l1;
    node *q = l2;
    node *ptr;
    if (p->data < q->data)
    {
        ptr = p;
        p = p->next;
    }
    else
    {
        ptr = q;
        q = q->next;
    }
    node *ans = ptr;
    while (p != NULL and q != NULL)
    {
        if (p->data < q->data)
        {
            ptr->next = p;
            ptr = p;
            p = ptr->next;
        }
        else
        {
            ptr->next = q;
            ptr = q;
            q = ptr->next;
        }
    }
    if (p == NULL)
    {
        ptr->next = q;
    }
    if (q == NULL)
    {
        ptr->next = p;
    }
    return ans;
}

node *merge(node *left, node *right)
{
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    node *ans;
    if (left->data <= right->data)
    {
        ans = left;
        left->next = merge(left->next, right);
    }
    else
    {
        ans = right;
        right->next = merge(left, right->next);
    }
    return ans;
}

node *merge_sort_list(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *temp = head;
    node *slow = head;
    node *fast = head;
    while (!fast and !fast->next)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;
    node *left = merge_sort_list(head);
    node *right = merge_sort_list(slow);
    return merge(left, right);
}

node *rev_rec(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *smallans = rev_rec(head->next);
    node *temp = smallans;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallans;
}

node *reverse(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *n = NULL;
    node *p = NULL;
    node *ptr = head;
    while (ptr != NULL)
    {
        n = ptr->next;
        ptr->next = p;
        p = ptr;
        ptr = n;
    }
    return p;
}

int main()
{
    // node* l1 = NULL;
    // node* l2 = NULL;
    // l1 = create(l1);
    // l2 = create(l2);
    // display(l1);
    // display(l2);
    // display(merge_sorted_ll(l1,l2));
    // cout<<"The Mid of List is "<<list_mid(head)->data;
    // display(head);
    // node* new_head = merge_sort_list(head);
    // display(new_head);
    node *head = NULL;
    head = create(head);
    display(head);
    // head = rev_rec(head);
    head = reverse(head);
    display(head);
    return 0;
}
