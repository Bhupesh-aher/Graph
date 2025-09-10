#include<bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    //        node parent
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbourNode: adj[node]){
            if(!vis[neighbourNode]){
                vis[neighbourNode] = 1;
                q.push({neighbourNode, node});
            }
            // neighbourNode is visited previously and it's not parent of the current node 
            // that means someone has already touched this neighbourNode before the current node
            // means there is cycle in a graph
            else if(parent != neighbourNode){
                return true;
            }
        }
    }
    return false;
}

// TC - O(N) + O(2E) = O(N + 2E)            2E = no of degrees (no of neighbour nodes)
// SC - O(N) + O(N) = O(N)                  queue, vis

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

    int src = 1;
    int vis[n + 1] = {0};
     

    bool res = detect(src, adj, vis);
    if(res != 0) cout << "There is a cycle in a graph";
    else cout << "There is no cycle";
    
} 



// input

// 7 7

// 1 2
// 1 3
// 2 5
// 3 4
// 3 6
// 5 7
// 6 7


// 7 6
// 1 2
// 1 5
// 2 3
// 5 6 
// 3 4
// 6 7