#include<bits/stdc++.h>
using namespace std;

// src node is 0
// from src node we need to find shortest dist for each node
// from node 0 to node 1 shortest path
// from node 0 to node 2 shortest path
// and so on till last node 
// if last node is 6
// node 0 to node 6 shortest path





// If graph has negative edge weights or the graph has negative cycles
// That's when you should implement the bellman ford alogrithm


// Bellman Ford 

vector<int> bellmanFord(int V, vector<vector<int>> edges, int src){
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i ++){            // O(V * E)
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}



// If want detect the negative cycle exist or not 
// need to do Nth iteration (relaxation) as well to check negative cycle


vector<int> bellmanFord(int V, vector<vector<int>> edges, int src){
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i ++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth relaxation to check negative cycle exist or not
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            return {-1};         // means we are updating dist in Nth iteration means there is negative cycle (notes) 
        }
    }
    return dist;                // otherwise return dist 
    
}



// TC - O(V * E) 


int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, -2}, {1, 5, -3}, {2, 4, 3}, {3, 2, 6}, {3, 4, -2}, {5, 3, 1}};
    int src = 0;
    vector<int> res = bellmanFord(n, edges, src);
    
    for(auto it: res) cout << it << " ";
}





// n m 
// 6 7
// 0 1 5
// 1 2 -2
// 1 5 -3
// 2 4 3 
// 3 2 6
// 3 4 -2 
// 5 3 1








