#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int min_steps_rec(int n){
    if(n==1){
        return 0;
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n%3==0){
        a = min_steps_rec(n/3);
    }
    if(n%2==0){
        b = min_steps_rec(n/2);
    }
    c = min_steps_rec(n-1);
    return 1+min(min(a,b),c);
}

int min_steps_memo(int n, vector<int> &ans){
    if(n==1){
        ans[n] = 0;
        return 0;
    }
    int b=INT_MAX,c=INT_MAX;
    if(ans[n-1]==-1){
        ans[n-1] = min_steps_memo(n-1,ans);
    }
    if(n%2==0){
        if(ans[n/2]==-1){
            ans[n/2]==min_steps_memo(n/2,ans);
        }
        b = ans[n/2];
    }
    if (n % 3 == 0)
    {
        if (ans[n / 3] == -1)
        {
            ans[n / 3] == min_steps_memo(n / 3, ans);
        }
        c = ans[n / 3];
    }
    ans[n] = 1+min(ans[n-1],min(b,c));
    return ans[n];
}


int min_steps_dp(int n,vector<int>& ans){
    if(n==1){
        return 0;
    }
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    for(int i=4;i<=n;i++){
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(i%3==0){
            a = ans[i/3];
        }
        if(i%2==0){
            b = ans[i/2];
        }
        c = ans[i-1];
        ans[i] = 1+min(a,min(b,c));
    }
    return ans[n];
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    vector<int> ans(n+1,-1); 
    cout<<min_steps_rec(n)<<"\n";
    // cout<<min_steps_memo(n,ans)<<"\n";
    cout<<min_steps_dp(n,ans)<<"\n";
    return 0;
}
