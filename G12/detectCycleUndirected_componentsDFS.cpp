#include<bits/stdc++.h>
using namespace std;

bool detect(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto neighbour: adj[node]){
        if(!vis[neighbour]){
            if(detect(neighbour, node, adj, vis) == true) return true;
        }
        // neighbourNode is visited previously and it's not parent of the current node 
        // that means someone has already touched this neighbourNode before the current node
        // means there is cycle in a graph
        else if(parent != neighbour){
                return true;
        }
    }
    return false;
}


bool isCylce(int V, vector<int> adj[]){
    int vis[V + 1] = {0};
    // if graph has broken down into multiple components this is how we check for cycle
    // we do this for loop always when graph has broken down into multiple components
    
    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            if(detect(i, -1, adj, vis) == true){
                return true;            // if found cycle in any component. we can say that graph has a cycle (we say a graph to have a cycle if any of the component has a cycle)
            }
        }
    }
    return false;
}


// TC - O(N) + O(2E) = O(N + 2E) + O(N)            2E = no of degrees (no of neighbour nodes)
                                // for loop in iscycle()
// SC - O(N) + O(N) = O(N)                  auxillary stack, vis



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

    bool res = isCylce(n, adj);
    if(res != 0) cout << "There is a cycle in a graph";
    else cout << "There is no cycle";
    
    
} 



// input

// test case 1 -
// no cycle 

// 6 3

// 1 2
// 3 4
// 5 6


// test case 2 -
// has cycle in a one of the compoent

// 7 5
// 1 2
// 2 3
// 3 1    cycle in component 1
// 4 5
// 6 7
