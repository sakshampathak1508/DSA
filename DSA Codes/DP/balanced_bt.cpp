#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int balanced_bt(int h){
    if(h<=1){
        return 1;
    }
    int x = balanced_bt(h-1);
    int y = balanced_bt(h-2);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int ans = (temp1+temp2)%mod;
    return ans;
}

int balanced_bt_memo(int h,vector<long long int>& ans){
    ans[0]=1;
    ans[1] = 1;
    if(ans[h-1]==-1){
        ans[h-1] = balanced_bt(h-1); 
    }
    if(ans[h-2]==-1){
        ans[h-2] = balanced_bt(h-2); 
    }
    return ans[h-1]*ans[h-1]+2*ans[h-1]*ans[h-2];
}

int balanced_bt_dp(int h,vector<long long int>& ans){
    ans[0]=1;
    ans[1] = 1;
    for(int i=2;i<=h;i++){
        ans[i] = ans[i-1]*ans[i-1]+2*ans[i-1]*ans[i-2];
    }
    return ans[h];
    
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<long long int> ans(n+1,-1);
    cout<<balanced_bt(n)<<"\n";
    // cout<<balanced_bt_memo(n,ans)<<"\n";
    cout<<balanced_bt_dp(n,ans)<<"\n";
    return 0;
}
