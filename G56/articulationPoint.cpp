#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<int> &mark){
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer ++;
    int child = 0;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, adj, tin, low, mark);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child ++;
        }
        else {
            low[node] = min(low[node], tin[it]);
        }
    }
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
}


vector<int> articulationPoint(int n, vector<int> adj[]){
    int tin[n];
    int low[n];
    vector<int> vis(n, 0);
    vector<int> mark(n, 0);
    
    for(int i = 0; i < n; i++){                     // if graph has multiple components
       if(!vis[i]){
            dfs(i, -1, vis, adj, tin, low, mark);
       }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(mark[i] == 1) ans.push_back(i);
    }

    if(ans.size() == 0) return {-1};
    return ans;
}


// TC - O(V + 2E) 
// SC - O(4v) 

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

    vector<int> res = articulationPoint(n, adj);

    cout << "Articulation points for given input graph is " << endl;
    for(auto it: res) cout << it << " ";
} 


// You can try this graph as well it is 0 based indexing graph 

// n m 
// 7 8

// 0 1
// 0 2
// 0 3
// 2 3
// 2 4
// 2 5
// 4 6
// 5 6