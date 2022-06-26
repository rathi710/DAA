#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[],int v,int s){
    vector<bool> visited(v,false);
    queue<int> q;
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v: adj[u])
        {
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main(){
    int v=4;
    vector<int> adj[v];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,3);

    bfs(adj,v,1);
    
}