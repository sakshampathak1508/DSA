#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
};

void display(node* head){
    node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"<->";
        ptr = ptr->next;
    }
    cout<<"\n";
}

node* insert_at_beg(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    p->next = ptr;
    ptr->prev = p;
    p->prev = NULL;
    head = p;
    return head;
}

void insert_at_end(node* head,int val){
    node* ptr = head;
    node* p = new node();
    p->data = val;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = p;
    p->prev = ptr;
    p->next = NULL;

}

void insert_at_mid(node* head,int pos,int val){
    node* ptr = head;
    node* p = new node();
    int i=1;
    while(i!=pos-1){
        ptr = ptr->next;
        i++;
    }
    p->data = val;
    p->next = ptr->next;
    p->prev = ptr;
    ptr->next = p;
}

int main(){
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();

    // creation
    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;
    
    third->data = 30;
    third->next = fourth;
    third->prev = second;
    
    fourth->data = 40;
    fourth->next = NULL;
    fourth->prev = third;
    // creation

    display(head);
    head = insert_at_beg(head,100);
    display(head);
    insert_at_end(head,500);
    display(head);
    insert_at_mid(head,4,300);
    display(head);
    return 0;
}
