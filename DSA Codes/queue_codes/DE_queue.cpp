#include <iostream>
#include <stdio.h>
using namespace std;

class queue
{
int front;
int rear;
int size;
int *arr;
public:
    queue()
    {
        cout << "Enter the size of the queue: ";
        cin >> size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void display()
    {
        if(front==-1){
            cout<<"DeQueue Is Empty\n";
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout << "\n";
    }
    void enqueue_from_start(int val){
        if(front==-1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(front!=0){
            front--;
            arr[front] = val;
        }
        else{
            cout<<"Queue Overflow\n";
        }
    }
    void enqueue_from_end(int val){
        if(rear>=size-1){
            cout<<"Queue OverFlow\n";
        }
        else{
            if(front==-1){
                front++;
                rear++;
            }
            else{
                rear++;
            }
            arr[rear] = val;
        }
    }
    int dequeue_from_start(){
        if(front==-1){
            cout<<"Queue Underflow\n";
            return -1;
        }
        else{
            int val = arr[front];
            if(front==rear){
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
            return val;
        }
    }
    int dequeue_from_end(){
        if(front==-1){
            cout<<"Queue Underflow\n";
            return -1;
        }
        else{
            int val = arr[rear];
            if(front==rear){
                front = -1;
                rear = -1;
            }
            else{
                rear--;
            }
            return val;
        }
    }

};

int main()
{
    queue *q = new queue();
    int ch, ele;
    while (true)
    {
        cout << "\n1= Display\n2= Enqueue From Rear\n3= Enqueue From Front\n4= Dequeue From end\n5= Dequeue From Front\n6= Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The Queue is: \n";
            q->display();
            break;
        case 2:
            cout << "Enter the element to enqueue from Rear \n";
            cin >> ele;
            q->enqueue_from_end(ele);
            break;
        case 3:
            cout << "Enter the element to enqueue from Front \n";
            cin >> ele;
            q->enqueue_from_start(ele);
            break;
        case 4:
            cout << "The Element Dequeued from Rear is: " << q->dequeue_from_end() << endl;
            break;
        case 5:
            cout << "The Element Dequeued from Front is: " << q->dequeue_from_start() << endl;
            break;
        case 6:
            exit(1);
        default:
            cout << "oops enter the correct option\n";
            break;
        };
    }
    return 0;
}
