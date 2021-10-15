#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void display(node* head){
    node* ptr = head;
    do{
        cout<<ptr->data<<"-";
        ptr = ptr->next;
    }while(ptr!=head);
    cout<<"\n";
}

node* insert_at_beg(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    p->next = ptr;
    p->prev = ptr->prev;
    ptr->prev = p;
    p->prev->next = p;
    head = p;
    return head;
}

void insert_at_end(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    p->next = ptr;
    p->prev = ptr->prev;
    ptr->prev = p;
    p->prev->next = p;
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
    p->next->prev = p;
    p->prev = ptr;
}

int main()
{
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();

    // creation
    head->data = 10;
    head->next = second;
    head->prev = fourth;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = fourth;
    third->prev = second;

    fourth->data = 40;
    fourth->next = head;
    fourth->prev = third;
    // creation

    display(head);
    head = insert_at_beg(head,5);
    display(head);
    insert_at_end(head,50);
    display(head);
    insert_at_mid(head,3,15);
    display(head);
    return 0;
}
