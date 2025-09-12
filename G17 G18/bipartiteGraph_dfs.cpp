#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> convertToAdjList(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> adjList(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { // avoid duplicate entries
            if(matrix[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);  // ✅ add reverse edge
            }
        }
    }

    return adjList;
}

bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color){
    color[node] = col;
    for(auto it: adj[node]){
        if(color[it] == -1){
            if(dfs(it, !col, adj, color) == false) return false;
        }
        else if(color[it] == col){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> color(V, -1);  // -1 means uncolored

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            if (dfs(i, 0, adj, color) == false) {
                return false; // One component is not bipartite
            }
        }
    }
    // all components are bipartite so return true
    return true;
}


// TC and SC is similar to DFS (dfs.cpp) whatever that takes this problem is also taking same 

// TC - O(N) + O(2E)     2E = no of degrees (no of neighbour nodes)
// SC - O(2N) = O(N)      color, auxiliary stack

int main(){
     
    // Input graph as adjacency matrix
    vector<vector<int>> matrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    // Convert matrix to adjacency list
    vector<vector<int>> adj = convertToAdjList(matrix);

    bool res = isBipartite(adj);
    if(res != 0) cout << "The graph is Bipartite";
    else cout << "The graph is not Bipartite";
} 