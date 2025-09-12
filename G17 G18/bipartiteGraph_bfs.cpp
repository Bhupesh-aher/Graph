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

bool bfs(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = !color[node];
                q.push(it);
            } else if (color[it] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> color(V, -1);  // -1 means uncolored

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            if (!bfs(i, adj, color)) {
                return false; // One component is not bipartite
            }
        }
    }
    // all components are bipartite so return true
    return true;
}

// TC and SC is similar to BFS (bfs.cpp) whatever that takes this problem is also taking same 

// TC - O(N) + O(2E)     2E = no of degrees (no of neighbour nodes)
// SC - O(3N) = O(N)      color, queue

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




// {0, 1, 1, 1},
// {1, 0, 1, 0},
// {1, 1, 0, 1},
// {1, 0, 1, 0}
// This graph is not Bipartit
