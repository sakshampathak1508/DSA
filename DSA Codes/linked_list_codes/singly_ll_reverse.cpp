#include <iostream>
#include <stdio.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

void display(node* head){
    node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"-";
        ptr = ptr->next;
    }
    cout<<"\n";
}

void rev_display(node* head){
    node * ptr  = head;
    if(ptr==NULL){
        return;
    }
    rev_display(ptr->next);
    cout<<ptr->data<<"-";
}

node* reverse(node* head){
    node* ptr = head;
    node* n = NULL;
    node* p = NULL;
    while(ptr!=NULL){
        n = ptr->next;
        ptr->next = p;
        p = ptr;
        ptr = n;
    }
    return p;
}

node* reverse_rec(node* head,node* ptr){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        head = ptr;
        return ptr;
    }
    node* curr = reverse_rec(head,ptr->next);
    curr->next = ptr;
    ptr->next = NULL;
    return ptr;
}

/**
 * Definition for singly-linked list.
 * struct node {
 *     int val;
 *     node *next;
 *     node(int x) : val(x), next(NULL) {}
 * };
 */
node* reorder(node *head)
{
    node *slow = head;
    node *fast = head;
    node *ptr = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *ans = slow;
    node *p = NULL;
    node *n = NULL;
    while (slow != NULL)
    {
        n = slow->next;
        slow->next = p;
        p = slow;
        slow = n;
    }
    node* a = ptr;
    while (ptr != p)
    {
        ptr->next = slow;
        slow = slow->next;
        a = a->next;
        ptr = a;
    }
    return head;
}

int main(){
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    node *fifth = new node();
    node *sixth = new node();

    // creation
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;
    
    fifth->data = 50;
    fifth->next = sixth;
    
    sixth->data = 60;
    sixth->next = NULL;
    // creation
    display(head);
    head = reorder(head);
    display(head);

    // head = reverse(head);
    // display(head);

    return 0;
}
