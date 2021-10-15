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

void rev_display(node* head){
    node* ptr = head;
    if(ptr==NULL){
        return;
    }
    rev_display(ptr->next);
    cout<<ptr->data<<"<->";
}

// node* reverse(node* head){
//     node* ptr = head;
//     node* p = NULL;
//     while(ptr!=NULL){
//         ptr->prev = ptr->next;
//         ptr->next = p;
//         p = ptr;
//         ptr = ptr->prev;
//     }
//     return p;
// }
node* reverse(node* head){
    node* ptr = head;
    node* p = NULL;
    while(ptr!=NULL){
        ptr->prev = ptr->next;
        ptr->next = p;
        p = ptr;
        ptr = ptr->prev;
    }
    return p;
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
    // rev_display(head);
    head = reverse(head);
    display(head);
    return 0;
}
