#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class Graph{
    public:
        int vertices;
        int ** edges;
        bool* visited;
        Graph(int n){
            this->vertices = n;
            edges = new int*[vertices];
            for(int i=0;i<vertices;i++){
                edges[i] = new int[vertices];
                for(int j=0;j<vertices;j++){
                    edges[i][j] = 0;
                }
            }
            visited = new bool[vertices];
            for(int i=0;i<vertices;i++){
                visited[i] = false;
            }
        }
        void clear_visited()
        {
            for(int i=0;i<vertices;i++){
                visited[i] = false;
            }
        }
};

void make_graph(Graph* g,int e){
    for(int i=0;i<e;i++){
        int f,s;
        cout<<"enter the 1st and second ertex the edge is between: \n";
        cin>>f>>s;
        g->edges[f][s] = 1;
        g->edges[s][f] = 1;
    }
}

void print_dfs(Graph* g,int sv){
    cout<<sv<<endl;
    g->visited[sv] = true;
    for(int i=0;i<g->vertices;i++){
        if(i==sv){
            continue;
        }
        if(g->edges[sv][i]==1){
            if (g->visited[i]){
                continue;
            }
            print_dfs(g, i);
        }
    }
}

void print_bfs(Graph *g, int sv){
    queue<int> q;
    q.push(sv);
    g->visited[sv] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<endl;
        for(int i=0;i<g->vertices;i++){
            if(i==front){
                continue;
            }
            if(g->edges[front][i]==1 and !g->visited[i]){
                q.push(i);
                g->visited[i] = true; 
            }
        }
    }
}

int main(){
    Graph *g = new Graph(8);
    make_graph(g,9);
    cout<<"DFS: \n";
    print_dfs(g,0);
    g->clear_visited();
    cout<<endl;
    cout<<"BFS: \n";
    print_bfs(g,0);
    return 0;
}
