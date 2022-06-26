// Approach:
// 1 - Sort all the edges according to their weight
// 2 - Greedily pick minimum edge and make sure the two nodes belong to different components(using disjoint set data structure
//     findParent operation). Remember, if they belong to same component it would indicate we would be having cycles which is
//     not possible in a MST.
// 3 - Also, once we a node to be a part of the MST, we must join the two components using the union operation of DSU.

// Time Complexity: O(ElogE)+O(E*4*alpha), ElogE for sorting and E*4*alpha for findParent operation ‘E’ times
// Space Complexity: O(N). Parent array+Rank Array

#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) 
{
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); //path compression kia hua yha 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

	sort(edges.begin(), edges.end(), comp);  //sorting according to the weights
	
	//initialize parents and rank
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 

	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 

	for(auto it : edges) {
        //check if both vertex belongs to same or different set(or their parents are same or not)
        //if different, add the cost, include those in mst, update in set using union
	    if(findPar(it.v, parent) != findPar(it.u, parent)) { 
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
    //printing minimum cost 
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}



