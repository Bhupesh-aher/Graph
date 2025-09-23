#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int V, vector<pair<int, int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src = 0;
    vector<int> dist(V);
    for(int i = 0; i < V; i++) dist[i] = 1e9;
    dist[src] = 0;
    //      dist, node
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode]  = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;

}

// TC - O(E log V)
// E = total no of edges
// V = no of nodes

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n]; // 0-based indexing

    // the entire graph has been stored here -  weighted directed graph
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Directed edge u → v with weight w

    }
    
    vector<int> res = dijkstra(n, adj);

    cout << "The shortest dist from src node to other nodes are" << endl; 

    for(auto it: res) cout << it << " ";
} 


// Input
// n m
// 6 8
// 0 1 4
// 0 2 4 
// 1 2 2
// 2 3 3 
// 2 4 1
// 2 5 6
// 3 5 2
// 4 5 3

// u - > v with wt