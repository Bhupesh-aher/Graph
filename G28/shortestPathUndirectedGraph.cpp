#include<bits/stdc++.h>
using namespace std;


// The edge weight is 1 for all the edges

// src node is 0
// from src node we need to find shortest dist for each node
// from node 0 to node 1 shortest path
// from node 0 to node 2 shortest path
// and so on till last node 
// if last node is 6
// node 0 to node 6 shortest path

// In the problem they clearly mentioned that src node will always be 0
// But we solve this problem for any given src node
// so this code will work if you give any node as src node





vector<int> shortestPath(int n, vector<int> adj[]){

    int src = 0;
    vector<int> dist(n);
    for(int i = 0; i <n; i++) dist[i] = 1e9;
    dist[src] = 0;

    queue< int> q;
    q.push(src);

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    // multiple components if we not reach to a node from src node in that case dist will be -1
    // for that node

    vector<int> ans(n, -1);
    for(int i = 0; i <n; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }
    return ans;

}



// TC -  O(V + 2E)    
// SC - O(2V)  queue, dist


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
        adj[v].push_back(u);  

    }
    

   vector<int> res = shortestPath(n, adj);
   
   cout << "The shortest dist from src node to other nodes are " << endl;
   for(auto it: res) cout << it << " ";
} 


// Input
// n m
// 9 11

// 0 1 
// 0 3  
// 1 2 
// 1 3  
// 2 6 
// 3 4 
// 4 5 
// 5 6 
// 6 7 
// 6 8 
// 7 8

// u - > v 
// All edge weights are 1