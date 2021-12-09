#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s,string t){
    if(s.empty() or t.empty()){
        return 0;
    }

    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }

    int a = lcs(s,t.substr(1));
    int b = lcs(s.substr(1),t);
    int c = lcs(s.substr(1),t.substr(1));
    return max(a,max(b,c)); 
}
int lcs_memo(string s,string t,vector<vector<int>>& ans){
    int m = s.size();
    int n = t.size();
    if (m == 0 or n == 0)
    {
        return 0;
    }
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }

    if (s[0] == t[0])
    {
        ans[m - 1][n - 1] = lcs_memo(s.substr(1), t.substr(1), ans);
        ans[m][n] = 1 + ans[m - 1][n - 1];
    }
    else
    {
        ans[m][n - 1] = lcs_memo(s, t.substr(1), ans);
        ans[m - 1][n] = lcs_memo(s.substr(1), t, ans);
        ans[m][n] = max(ans[m][n - 1], ans[m - 1][n]);
    }
    return ans[m][n];
}



int main(){
    string s;
    string t;
    cout<<"enter s: ";
    cin>>s;
    cout<<"enter t: ";
    cin>>t;

    cout<<"Lcs is : "<<lcs(s,t);
    return 0;
}
