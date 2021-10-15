#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node* create(node* head,int n){
    // head must be null for list creation
    head = new node();
    cout<<"Enter Head Element: ";
    cin>>head->data;
    head->next = NULL;
    node* ptr = head;
    for(int i=0;i<n-1;i++){
        node* p = new node();
        ptr->next = p;
        cout<<"Enter the data for next node: ";
        cin>>p->data;
        p->next = NULL;
        ptr = p;
    }
    return head;
}

void display(node* head){
    node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"-";
        ptr = ptr->next;
    }
    cout<<"\n";
}

int main()
{   
    node* head = NULL;
    head = create(head,5);
    display(head);
    cout<<head->next->data;
    return 0;
}
