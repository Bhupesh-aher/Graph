#include<bits/stdc++.h>
using namespace std;



int main(){
    
    int n, m;
    cin >> n >> m;
    int adj[n + 1][n + 1] = {0}; // // adjacency matrix with 1-based indexing

    // the entire graph has been stored here - undirected graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // Print adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
} 

// TC - O(m)
// SC - O(n^2)  