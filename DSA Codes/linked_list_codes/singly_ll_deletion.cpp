#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "-";
        ptr = ptr->next;
    }
    cout << "\n";
}

node* del_at_beg(node* head){
    node* ptr = head;
    head = ptr->next;
    delete ptr;
    return head;
}

void del_at_end(node* head){
    node* p = head;
    node* q = head->next;
    while(q->next!=NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    delete q;
}

void del_at_mid(node* head, int pos){
    node* p = head;
    node* q = head->next;
    int i=1;
    while(i!=pos-1){
        q = q->next;
        p = p->next;
        i++;
    }
    p->next = q->next;
    delete q;
}

int main()
{
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
    fourth->next = NULL;


    // creation
    display(head);
    // head = del_at_beg(head);
    // del_at_end(head);
    del_at_mid(head,3);
    display(head);

    return 0;
}
