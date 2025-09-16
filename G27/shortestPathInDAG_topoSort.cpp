#include<bits/stdc++.h>
using namespace std;

// src node is 0
// from src node we need to find shortest dist for each node
// from node 0 to node 1 shortest path
// from node 0 to node 2 shortest path
// and so on till last node 
// if last node is 6
// node 0 to node 6 shortest path

// In the problem they clearly mentioned that src node will always be 0
// But we solve this problem for any given src
// so this code will work if you give any node as src node




void dfs(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            dfs(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int n, vector<pair<int, int>> adj[]){

    // step 1 - find the topo sort for given graph
    int vis[n] = {0};
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    int src = 4; // Assuming this is our src node (notes)

    
    // step 2 - Do the dist[] thing by relaxing edges 
    vector<int> dist(n);
    for(int i = 0; i <n; i++) dist[i] = 1e9;
    dist[src] = 0;

    // O(N)
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){                // O(M)
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}


// TC -  O(V + E) + O(N + M)             M = E (edges)
//        dfs         step 2

// SC - O(2V) 
// stack, vis. Not considering the auxiliary stack space


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
    

   vector<int> res = shortestPath(n, adj);
   
   cout << "The shortest dist from src node to other nodes are " << endl;
   for(auto it: res) cout << it << " ";
} 


// Input
// n m
// 7 8

// 0 1 2
// 1 3 1 
// 2 3 3
// 4 0 3 
// 4 2 1
// 5 4 1
// 6 4 2
// 6 5 3

// u - > v with wt