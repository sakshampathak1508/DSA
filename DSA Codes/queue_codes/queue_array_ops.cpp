#include <iostream>
#include <stdio.h>
using namespace std;

class queue
{
public:
    int size;
    int rear;
    int front;
    int *arr;
    queue()
    {
        cout << "Enter the size of the queue: ";
        cin >> size;
        rear = -1;
        front = -1;
        arr = new int[size];
    }
};

void display(queue* q){
    for(int i=q->front+1;i<=q->rear;i++){
        cout<<q->arr[i]<<" ";
    }
    cout<<endl;
}

bool isempty(queue* q){
    if(q->rear==q->front){
        return true;
    }
    return false;
}

bool isfull(queue *q)
{
    if(q->rear==q->size-1){
        return true;
    }
    return false;
}

void enqueue(queue* q,int data){
    if(isfull(q)){
        cout<<"Queue OverFlow! \n";
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(queue* q){
    if(isempty(q)){
        cout<<"Queue UnderFlow! \n";
        return -1;
    }
    int val = q->arr[q->front+1];
    q->front++;
    return val;
}

int dequeue(queue* q,int index){
    for (int i = index; i < q->size; i++)
    {
        q->arr[i] = q->arr[i + 1];
    }
    q->rear--;
}

int main()
{
    queue* q = new queue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    display(q);
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    cout<<"Dequeue  = "<<dequeue(q)<<"\n";
    display(q);
    
    return 0;
}
