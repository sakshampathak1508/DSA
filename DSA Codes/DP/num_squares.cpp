#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int num_squares_rec(int n){
    if(sqrt(n)-floor(sqrt(n))==0){
        return 1;
    }
    if(n<=3){
        return n;
    }
    int ans = n;
    for(int i=1;i*i<n;i++){
        int a = 1+num_squares_rec(n-(i*i));
        ans = min(ans,a);
    }
    return ans;
}

int num_squares_memo(int n,vector<int>& ans){
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<=n;i++){
        ans[i] = INT_MAX;
        for(int j=1;i-(j*j)>=0;j++){
            ans[i]  = min(ans[i],ans[i-(j*j)]);
        }
        ans[i]++;
    }
    return ans[n];
}

int num_squares_dp(int n,vector<int>& ans){
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for(int i=4;i<n;i++){
        ans[i] = i;
        for(int j=1;i-(j*j)>=0;j++){
            ans[i] = min(ans[i],1+ans[i-(j*j)]);
        }   
    }   
    return ans[n];
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>ans(n+1);
    cout<<num_squares_memo(n,ans)<<"\n";
    cout<<num_squares_dp(n,ans)<<"\n";
    // for(int i=0;i<n+1;i++){
    //     cout<<ans[i]<<"\n";
    // }
    // cout<<num_squares_rec(n)<<"\n";
    return 0;
}
