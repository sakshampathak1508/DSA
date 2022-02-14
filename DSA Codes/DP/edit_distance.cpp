#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int edit_dis_rec(string s,string t){
    if(s.size()==0 or t.size()==0){
        return max(s.size(),t.size());
    }
    
    if(s[0]==t[0]){
       return edit_dis_rec(s.substr(1),t.substr(1));
    }
    // insert
    int a = edit_dis_rec(s.substr(1),t);
    // delete
    int b = edit_dis_rec(s,t.substr(1));
    // update
    int c = edit_dis_rec(s.substr(1),t.substr(1));
    return min(a,min(b,c))+1;
}

int edit_distance_dp(string word1,string word2){
    int m = word1.size();
    int n = word2.size();
    if (m == 0 or n == 0)
    {
        return max(m, n);
    }
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++)
    {
        ans[0][i] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        ans[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[m - i] == word2[n - j])
            {
                ans[i][j] = ans[i - 1][j - 1];
            }
            else
            {
                ans[i][j] = min(ans[i - 1][j - 1], min(ans[i][j - 1], ans[i - 1][j])) + 1;
            }
        }
    }
    return ans[m][n];
}

int main(){
    string s = "abcd";    
    string t = "zxcd";


    return 0;
}
