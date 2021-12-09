#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class Edge{
    public:
        int start;
        int dest;
        int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

int findparent(int v , int* parent){
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v],parent);
}

void kruskals(Edge* input,int n,int e){
    sort(input,input+e,compare);
    Edge* output = new Edge[n-1];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int count = 0;
    int i=0;
    while(count!=n-1){
        Edge current_edge = input[i];
        int source_parent = findparent(current_edge.start,parent);
        int dest_parent = findparent(current_edge.dest,parent);

        if(source_parent!=dest_parent){
            output[count] = current_edge;
            count++;
            parent[source_parent] = dest_parent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(output[i].start < output[i].dest){
            cout<<output[i].start<<" "<<output[i].dest<<" "<<output[i].weight<<"\n";
        }
        else{
            cout<<output[i].dest<<" "<<output[i].start<<" "<<output[i].weight<<"\n";
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    Edge* input = new Edge[e];    
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].start = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskals(input,n,e);
    return 0;
}
