// Circular Queue
#include <iostream>
#include <stdio.h>
using namespace std;

class c_queue{
    public:
        int *arr;
        int front;
        int rear;
        int size;
        c_queue(){
            cout<<"Enter the size of the array ";
            cin>>size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }
        bool isempty(){
            if(front==-1){
                return true;
            }
            return false;
        }
        bool isfull(){
            if(front==0 and rear == size-1){
                return true;
            }
            if(front == rear+1){
                return true;
            }
            return false;
        }
        void enqueue(int val){
            if(isfull()){
                cout<<"Queue OverFlow\n";
                return;
            }
            if(front==-1){
                front = 0;
            }
            rear = (rear+1)%size;
            arr[rear] = val;
            cout<<"The valued Enqueued in the queue is: "<<arr[rear]<<endl;
        }
        int dequeue(){
            if(isempty()){
                cout<<"Queue Underflow\n";
                return -1;
            }
            int val = arr[front];
            if(front==rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front+1)%size;
            }
            return val;
        }
        void display(){
            int i;
            for(i=front;i!=rear;i=(i+1)%size){
                cout<<arr[i]<<" ";
            }
            cout<<arr[i]<<endl;
        }
};

int main(){
    c_queue *q = new c_queue();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->display();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    q->enqueue(70);
    cout<<"Front = "<<q->arr[q->front]<<endl;
    cout << "Rear = " << q->arr[q->rear] << endl;
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    q->display();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    q->enqueue(100);
    q->enqueue(200);
    q->display();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    cout<<"Dequeued from the queue is : "<<q->dequeue();
    q->enqueue(300);
    q->display();
    cout<<"Front = "<<q->arr[q->front]<<endl;
    cout << "Rear = " << q->arr[q->rear] << endl;
    return 0;
}
