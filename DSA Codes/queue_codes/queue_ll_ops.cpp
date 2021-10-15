#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
    int data;
    node* next;
};

node* front = NULL;
node* rear = NULL;

void display(){
    node* ptr =  front;
    while(ptr!=NULL){
        cout<<ptr->data<<"-";
        ptr = ptr->next;
    }
    cout<<"\n";
}

bool isempty(){
    if(front==NULL){
        return true;
    }
    return false;
}

bool isfull(){
    node* ptr = new node();
    if(ptr==NULL){
        return true;
    }
    delete ptr;
    return false;
}

void enqueue(int val){
    if(isfull()){
        cout<<"Queue OverFlow\n";
        return;
    }
    node* ptr = new node();
    ptr->data = val;
    ptr->next = NULL;
    if(isempty()){
        front = rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
    cout<<"Enqueued in the queue: "<<rear->data<<"\n";
}

int dequeue(){
    if(isempty()){
        cout<<"Queue Underflow: ";
        return -1;
    }
    node* ptr = front;
    int val = ptr->data;
    front = front->next;
    delete ptr;  
    return val;  
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    display();
    enqueue(60);
    enqueue(70);
    display();
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    cout << "Dequeued the element: " << dequeue() << endl;
    return 0;
}
