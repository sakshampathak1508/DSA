#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void rev(int num,int& s){
    if(num<=0){
        return;
    }
    int r = num%10;
    s = r+s*10;
    rev(num/10,s);
}

int rev_iter(int num){
    int r=0,s=0,temp=num;
    while(temp>0){
        r = temp%10;
        temp /=10;
        s = r+s*10;
    }
    return s;
}

int main(){
    int n = 1234;
    int s = 0;
    rev(n,s);
    cout<<s;
    return 0;
}
