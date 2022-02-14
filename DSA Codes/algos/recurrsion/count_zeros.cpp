#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int zeros(int n){
    if(n==0){
        return 0;
    }
    int r = n%10;
    if(r==0){
        return 1+zeros(n/10);
    }
    return zeros(n/10);
}

int main(){
    cout<<zeros(30204);
    return 0;
}
