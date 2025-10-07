#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges.push_back({node, it});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }

}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    // Created graph here                     
    for(auto it: connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);
    return bridges;
}

// TC - O(V + 2E) 
// SC - O(3V) +    O(V + 2E) 
//   tin, low, vis  adj


int main(){
    int n = 4;
    
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> bridges = criticalConnections(n, connections);


    cout << "Bridges in a Given Graph is " << endl;
    for(auto it: bridges){
        cout << it[0] <<  " " << it[1] << endl;
    }
    
} 


// You can try this graph as well it is 0 based indexing graph 

// n m 
// 12 14

// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 6 9
// 7 8
// 9 8
// 8 10
// 10 11
// 10 12
// 11 12