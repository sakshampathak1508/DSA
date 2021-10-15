#include <iostream>
#include <stdio.h>
using namespace std;

class stack{
    public:
        int top;
        int size;
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

void push(stack* s, char ch){
    if(isfull(s)){
        return;
    }
    s->top++;
    s->arr[s->top] = ch;
}

char pop(stack* s){
    if(isempty(s)){
        return -1;
    }
    char ch = s->arr[s->top];
    s->top--;
    return ch;
}

bool is_oper(char ch){
    if (ch == '+' or ch == '-' or ch == '*' or ch == '/'){
        return true;
    }
    return false;
}

int prec(char a){
    if(a=='+' or a=='-'){
        return 1;
    }
    else if(a=='*' or a=='/'){
        return 2;
    }
    return 0;
}

string infix_to_pos(string exp){
    stack* s = new stack(exp);
    string ans= "";
    for(int i=0;i<exp.size();i++){
        if(!is_oper(exp[i])){
            ans += exp[i]; 
        }
        else{
            if(prec(exp[i]) > prec(s->arr[s->top])){
                push(s,exp[i]);
            }
            else{
                while(prec(exp[i]) <= prec(s->arr[s->top])){
                    ans += pop(s);
                }
                push(s,exp[i]);
            }
        }
    }
    while(!isempty(s)){
        ans+= pop(s);
    }
    return ans;
}

int main(){
    string str = "x-y/z-k*d";
    cout<<infix_to_pos(str);
    return 0;
}
