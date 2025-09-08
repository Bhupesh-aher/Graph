#include<bits/stdc++.h>
using namespace std;


// This code works both for undirected and directed graph 
// just while taking input 
// in case of undirected u -> v and v -> u
// in case if directed u -> v
// that's the only change and that too while taking input. no change in dfsOfGraph() code


void dfsOfGraph(int node, vector<int> adj[], int vis[], vector<int> &dfs){
    vis[node]  = 1;
    dfs.push_back(node);
    // traverse all the neighbours of the node
    for(auto it: adj[node]){
        if(!vis[it]){
            dfsOfGraph(it, adj, vis, dfs);
        }
    }
}


// TC - O(N) + O(2E)        2E = no of degrees (no of neighbour nodes)
// SC - O(3N) = O(N)        vis, dfs, auxilary stack space


// TC - O(N) + O(2E) for undirected graph
// TC - O(N) + O(E) for directed graph O(E) no of edges in entire graph



int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1 based indexing

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

   
    vector<int> dfs;
    int vis[n + 1] = {0};
    int start = 1;
    dfsOfGraph(start, adj, vis, dfs);


    cout << "DFS traversal - " << endl;
    for(auto it: dfs) cout << it << " "; 
    
    
    
} 





// starting node = 1;
// input
// 8 8

// 1 2
// 1 3
// 2 5
// 2 6
// 3 7
// 3 4
// 7 8
// 4 8

