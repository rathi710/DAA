#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[],vector<bool> &visited,int s,int parent)
{
    visited[s]=true;
    cout<<s<<"  ";

    for(auto x: adj[s]){
        if(visited[x]==false){
            dfs(adj,visited,x,s);
        }
        else if(x!=parent)             //if x is already visited and not a parent
        {                  
            cout<<endl;
            cout<<"cycle exists";      //we found a back edge(cycle)
            return;
        }
       
    }
}


int main(){
    int v=4;
    vector<int> adj[v];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    // addEdge(adj,1,0);
    addEdge(adj,2,3);
    // addEdge(adj,2,0);
    // addEdge(adj,3,2);

    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfs(adj,visited,i,-1);
        }
    }
    
}