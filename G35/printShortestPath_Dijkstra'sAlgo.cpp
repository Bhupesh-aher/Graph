#include<bits/stdc++.h>
using namespace std;

// In The question it is mention start node = 1 and end node = 5 (nth node) always 
// print the shortest Path 
// we will use Dijkstra Algorithm
// Till now we find the value of the path instead here we need to print the path
// that is difference between this problem and what we learn previously 
// There can be multiple shortest path you just need to return any one of them 




// This code is my code and write by my own style

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int src, int dest){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V + 1, 1e9);

    dist[src] = 0;
    vector<int> parent(V + 1, -1);

        //  dist node
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    
    if(dist[dest] == 1e9) return {-1}; // we never reach the dest from src

    vector<int> path;
    int i = V;
    path.push_back(V);
    while(i != 1){                      // O(V)
        path.push_back(parent[i]);
        i = parent[i];
    }
    reverse(path.begin(), path.end());
    return path;
}






// This is strivers code

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int src, int dest){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V + 1, 1e9);

    dist[src] = 0;

    vector<int> parent(V + 1);
    for(int i = 1; i <=V; i++) parent[i] = i;

        //  dist node
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if(dist[dest] == 1e9) return {-1};          // we never reach the dest from src
    
    vector<int> path;
    int node = dest;
    while(parent[node] != node){        // O(V)
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}


// Above both code logic intution is exact same just the style of writting code is different

// TC same as dijkstra's algorithm just added O(V) in TC which we done for backtrack to get the path

// TC - O(E log V) + O(V)





int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1]; 

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});


    }
    
    int src = 1, dest = n;
    vector<int> res = dijkstra(n, adj, src, dest);  
    for(auto it: res) cout << it << " ";
} 







// Input
// n m
// 5 6
// 1 2 2
// 1 4 1 
// 2 3 4
// 2 5 5 
// 3 5 1
// 4 3 3

// u - > v with wt

