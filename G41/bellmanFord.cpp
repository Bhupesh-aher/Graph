#include<bits/stdc++.h>
using namespace std;



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
    
}





// n m 
// 7 10
// 0 4 5
// 0 1 2
// 0 6 7
// 1 2 3 
// 1 3 3 
// 4 6 2
// 2 5 1
// 3 6 3
// 3 5 1
// 6 5 1








