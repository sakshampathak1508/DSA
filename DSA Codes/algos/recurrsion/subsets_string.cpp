#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// print subsets 

void subsets(string ans,string str){
    if(str.empty()){
        cout<<ans<<" ";
        return;
    }
    char ch = str[0];
    if(ans[0]!=ch){
        subsets(ans+ch,str.substr(1));
        subsets(ans,str.substr(1));
    }
}

// Return vector<string>

vector<string> subsets_array(string ans,string str){
    if(str.empty()){
        vector<string> temp = {ans};
        return temp;
    }
    char ch = str[0];
    vector<string> left = subsets_array(ans+ch,str.substr(1));
    vector<string> right = subsets_array(ans,str.substr(1));
    left.insert(left.end(),right.begin(),right.end());
    return left;
}

vector<vector<int>> subsets_int(vector<int> arr,vector<int> temp){
    if(arr.size()==0){
        vector<vector<int>> ans;
        ans.push_back(temp);
        return ans;
    }
    int x = arr[0];
    arr.erase(arr.begin()+0);
    vector<vector<int>> left = subsets_int(arr,temp);
    temp.push_back(x);
    vector<vector<int>> right = subsets_int(arr,temp);
    left.insert(left.end(),right.begin(),right.end());
    return left;
}

vector<vector<int>> subsets_int_iter(vector<int> arr){
    vector<vector<int>> ans;
    ans.push_back({});
    for(int num: arr){
        int n = ans.size();
        for(int i=0;i<n;i++){
            vector<int> temp = ans[i];
            // temp.push_back(ans[i]);
            temp.push_back(num);
            ans.push_back(temp);
        }
    }
    return ans;
}



int main(){
    // vector<string> ans = subsets_array("","aac");
    // for(auto i: ans){
    //     cout<<i<<" ";
    // }
    vector<int> arr = {1,2,3};
    vector<int> temp;
    vector<vector<int>> ans = subsets_int_iter(arr);
    for(auto i: ans){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // subsets("","122");
    return 0;
}
