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

node* insert_at_beg(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    p->next = head;
    head = p;
    return head;
}

void insert_at_end(node* head,int val){
    node* ptr = head;
    node* p = new node();
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    p->data = val;
    p->next = NULL;
    ptr->next = p;
}

void insert_at_mid(node* head,int pos,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    int i=1;
    while(i!=pos-1){
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
}

node *insert_at_pos_rec(node *head, int pos, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (pos == 0)
    {
        node *ptr = new node();
        ptr->data = data;
        ptr->next = head;
        head = ptr;
        return head;
    }
    else
    {
        head->next = insert_at_pos_rec(head->next, pos - 1, data);
    }
    return head;
}

node *delete_at_pos_rec(node *head, int pos)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    else
    {
        head->next = delete_at_pos_rec(head->next, pos - 1);
    }
    return head;
}

int main(){
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();

// creation
    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;
// creation
    display(head);
    head = insert_at_beg(head,100);
    display(head);
    insert_at_end(head,200);
    display(head);
    insert_at_mid(head,4,500);
    display(head);
    return 0;
}
