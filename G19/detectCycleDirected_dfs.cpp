#include<bits/stdc++.h>
using namespace std;



bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
    vis[node] = 1;
    pathVis[node] = 1;

    // Travserse for adjacent nodes
    for(auto it: adj[node]){
        // When the node is not vistited
        if(!vis[it]){
            if(dfs(it, adj, vis, pathVis) == true) return true;
        }

        // if the node has been previously visisted
        // nut it has to be visited on the same path so we can say there is cycle
        else if(pathVis[it] == 1) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}



bool isCyclic(int V, vector<int> adj[]){
    int vis[V + 1] = {0};  // 1 - based indexing that's why V + 1
    int pathVis[V + 1] = {0};

    
    for(int i = 1; i <= V; i++){            // i<=V beacuse 1 based indexing
        if(dfs(i, adj, vis, pathVis) == true) return true; // cycle detected in the graph
    }
    return false;
}

// TC - O(V + E)        O(V + E) beacuse of directed graph and this what it takes for DFS in directed graph
// SC - O(V) + O(V) = O(2V) 

int main(){
     
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1-based indexing

    // the entire graph has been stored here -  directed graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool res = isCyclic(n, adj);
    if(res) cout << "Graph has a cycle";
    else cout << "Graph has no cycle";

} 


// 10 11
// 1 2
// 2 3
// 3 7
// 3 4
// 4 5
// 7 5
// 5 6
// 8 2
// 8 9
// 9 10
// 10 8