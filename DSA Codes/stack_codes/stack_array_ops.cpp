#include <iostream>
#include <stdio.h>
using namespace std;

class stack{
    public:
        int top;
        int size;
        int* arr;
        stack(){
            top = -1;
            cout<<"Enter the size of the stack: ";
            cin>>size;
            arr = new int[size];
        }
};

bool isempty(stack* s){
    if(s->top == -1){
        return true;
    }
    return false;
}

bool isfull(stack* s){
    if(s->top==s->size-1){
        return true;
    }
    return false;
}

void display(stack* s){
    for(int i=s->top;i>=0;i--){
        cout<<s->arr[i]<<"\n";
    }
    cout<<"\n";
}

void push(stack* s,int val){
    if(isfull(s)){
        cout<<"Stack Overflow can't push "<<val<<"\n";
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(stack* s){
    if(isempty(s)){
        cout<<"Stack UnderFlow can't pop "<<s->arr[s->top]<<"\n";
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int peek(stack* s,int pos){
    int index = s->top-pos+1;
    if(index<0){
        cout<<"Invalid Position\n";
        return -1;
    }
    return s->arr[index];
}

int stackTop(stack* s){
    if(isempty(s)){
        return -1;
    }
    return s->arr[s->top];
}

int stackBottom(stack* s){
    if(isempty(s)){
        return -1;
    }
    return s->arr[0];
}

int main(){
    stack* s = new stack();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    display(s);
    int ans = pop(s);
    display(s);
    cout<<"Stack Top = "<<stackTop(s)<<"\n";
    cout<<"Stack Bottom = "<<stackBottom(s)<<"\n";
    // cout<<peek(s,1)<<"\n";
    // cout<<peek(s,2)<<"\n";
    // cout<<peek(s,3)<<"\n";
    // cout<<peek(s,4)<<"\n";
    // cout<<peek(s,5)<<"\n";
    // cout<<peek(s,6)<<"\n";
    
    return 0;
}
