#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
};

void display(node *head)
{
    node *ptr = head;
    do
    {
        cout << ptr->data << "-";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "\n";
}

node* del_at_beg(node* head){
    node* ptr = head;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    head = ptr->next;
    delete ptr;
    return head;
}

void del_at_end(node* head){
    node* ptr = head->prev;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
}

void del_at_mid(node* head,int pos){
    node* ptr = head;
    int i=1;
    while(i!=pos){
        ptr = ptr->next;
        i++;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    delete ptr;
}

int main(){
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();

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
    // head = del_at_beg(head);
    // display(head);
    // del_at_end(head);
    del_at_mid(head,3);
    display(head);
    return 0;
}
