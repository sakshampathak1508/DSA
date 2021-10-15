#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node *prev;
};

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "\n";
}

node* del_at_beg(node* head){
    node* ptr = head;
    head = head->next;
    head->prev = NULL;
    delete ptr;
    return head;
}

void del_at_end(node* head){
    node* p = head;
    node* q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
}

void del_at_mid(node* head,int pos){
    node* p = head;
    node* q = head->next;
    int i=1;
    while(i!=pos-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    delete q;
}

int main(){
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();

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
    head = del_at_beg(head);
    display(head);
    // del_at_end(head);
    // display(head);
    del_at_mid(head,2);
    display(head);
    return 0;
}
