#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(vector<int> adj[],int V, int source, int dest){
    vector<bool> visited(V,false);
    queue<int> q;
    visited[source]=true;
    q.push(source);

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto it: adj[t]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
        }
    }
    return visited[dest];

}

int main(){
    int V,E;
    cout<<"no of vertex:"; cin>>V;
    cout<<"no of edges:"; cin>>E;

    vector<int> adj[V];
    
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u >> v;
        addEdge(adj,u,v);
    }

    int source,dest;
    cout<<"enter source:"; cin>>source;
    cout<<"enter destination:"; cin>>dest;

    if(bfs(adj,V,source,dest)) cout<<"path exists";
    else cout<<"path dont exist";

}