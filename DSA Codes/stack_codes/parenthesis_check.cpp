#include <iostream>
#include <stdio.h>
using namespace std;

class stack{
public:
    int size;
    int top;
    char* arr;   
    stack(string str){
        top = -1;
        size = str.length();
        arr = new char[size];
    }
};

bool isempty(stack* s){
    if(s->top==-1){
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

void push(stack* s,char val){
    if(isfull(s)){
        cout<<"Stack Overflow\n";
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

char pop(stack* s){
    if(isempty(s)){
        cout<<"Stack Underflow\n";
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

bool is_parenthesis(stack* s,string str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            push(s,str[i]);
        }
        else if(str[i]==')'){
            if(isempty(s)){
                return false;
            }
            pop(s);
        }
    }
    if(isempty(s)){
        return true;
    }
    return false;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    stack *s = new stack(str);

    if(is_parenthesis(s,str)){
        cout<<"The Parenthesis in the string is perfectly matched \n";
    }
    else{
        cout<<"The Parenthesis in the string is not perfectly matched \n";
    }
    return 0;
}
