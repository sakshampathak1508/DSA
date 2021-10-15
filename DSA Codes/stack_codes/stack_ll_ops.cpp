#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
    int data;
    node* next;
};

node *top = NULL;

bool isempty(){
    if(top==NULL){
        return true;
    }
    return false;
}

bool isfull(){
    node* p = new node();
    if(p==NULL){
        return true;
    }
    return false;
}

void display(node* top){
    node* ptr = top;
    while(ptr!=NULL){
        cout<<ptr->data<<"\n";
        ptr = ptr->next;
    }
    cout<<'\n';
}

node* push(int val){
    if(isfull()){
        cout<<"Stack Overflow\n";
        return NULL;
    }
    node* p = new node();
    p->data = val;
    p->next = top;
    top = p;
    return top; 
}

int pop(node* top){
    if(isempty()){
        cout<<"Stack Underflow\n";
    }
    node* ptr = top;
    int val = ptr->data;
    ::top = ptr->next;
    delete ptr;
    return val;
}

int peek(node* top,int pos){
    int i=0;
    node* ptr = top;
    while(i<pos-1 and ptr!=NULL){
        ptr = ptr->next;
        i++;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    return -1;

}

int stackTop(){
    if(isempty()){
        return -1;
    }
    return top->data;
}

int stackBottom(){
    if(isempty()){
        return -1;
    }
    node* ptr = top;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){
    top = push(10);
    top = push(20);
    top = push(30);
    top = push(40);
    display(top);
    cout<<"Popped : "<<pop(top)<<"\n";
    display(top);

    // cout<<"PEEK 5 =  "<<peek(top,5)<<"\n";
    // cout<<"PEEK 4 =  "<<peek(top,4)<<"\n";
    // cout<<"PEEK 3 =  "<<peek(top,3)<<"\n";
    // cout<<"PEEK 2 =  "<<peek(top,2)<<"\n";
    // cout<<"PEEK 1 =  "<<peek(top,1)<<"\n";
    cout<<"STACK TOP = "<<stackTop()<<endl;
    cout<<"STACK Bottom = "<<stackBottom()<<endl;
    return 0;
}
