#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


void make_graph(int e,vector<int> adj[]){
    for(int i=0;i<e;i++){
        int f,s;
        cout<<"enter 1st and 2nd vertex: \n";
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
}

void dfs(int sv,vector<int> adj[],vector<bool> &visited){
    cout<<sv<<", ";
    visited[sv] = true;
    for(auto i: adj[sv]){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }
}

void bfs(int sv, vector<int> adj[], vector<bool> &visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<", ";
        for(auto i: adj[front]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<int> adj[n];
    vector<bool> visited(n, false);
    make_graph(8,adj);
    // dfs(0,adj,visited);
    bfs(0,adj,visited);
    return 0;
}
