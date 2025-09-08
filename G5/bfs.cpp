#include<bits/stdc++.h>
using namespace std;


// This code works both for undirected and directed graph 
// just while taking input 
// in case of undirected u -> v and v -> u
// in case if directed u -> v
// that's the only change and that too while taking input no change in bfsOfGraph() code


vector<int> bfsOfGraph(int n, vector<int> adj[]){
    int vis[n + 1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;


    while(!q.empty()){                              // O(N)
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){                    // O(2E) visiting all neighbour nodes
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            } 
        }
    }
    return bfs;
}


// TC - O(N) + O(2E)        2E = no of degrees (no of neighbour nodes)
// SC - O(3N) = O(N)        vis, queue, bfs

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1 based indexing

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

   vector<int> bfs = bfsOfGraph(n, adj);

    cout << "BFS traversal - " << endl;
    for(auto it: bfs) cout << it << " "; 
    
    
} 





// starting node = 1;
// input
// 9 9

// 1 2
// 1 6
// 2 3
// 2 4
// 6 7
// 6 9
// 4 5
// 7 8
// 5 8