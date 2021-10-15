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
    do{
        cout<<ptr->data<<"-";
        ptr = ptr->next;
    }while (ptr!= head);
    cout<<"\n";
}

node* insert_at_beg(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    p->next = head;
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = p;
    head = p;
    return head;
}

void insert_at_end(node* head,int val){
    node* ptr = head;
    node* p = new node();
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = head;
    p->data = val;
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

int main(){
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();

    // creation
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;
    // creation
    display(head);
    head = insert_at_beg(head,100);
    display(head);
    insert_at_end(head,300);
    display(head);
    insert_at_mid(head,4,500);
    display(head);
    return 0;
}
