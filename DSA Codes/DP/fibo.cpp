#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int memo_fibo(int n,vector<int> &ans){
    if(n<=1){
        ans[n] = n;
        return n;
    }
    if(ans[n-1]==0){
        ans[n-1] = memo_fibo(n-1,ans);
    }
    if (ans[n - 2] == 0)
    {
        ans[n - 2] = memo_fibo(n - 2, ans);
    }
    ans[n] = ans[n-1]+ans[n-2];
    return ans[n];
}

int dp_fibo(int n,vector<int> &ans){
    ans[0] = 0;
    ans[1] = 1;
    if(n<=1){
        return ans[n];
    }   
    for(int i=2;i<n+1;i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int main(){
    int n=5;
    vector<int> ans(6);
    cout<<fibo(5)<<"\n";
    cout<<memo_fibo(5,ans)<<"\n";
    cout<<dp_fibo(5,ans)<<"\n";
    return 0;
}
