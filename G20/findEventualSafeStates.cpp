#include<bits/stdc++.h>
using namespace std;


// we solve this problem using cycle detection technique which we learn in (detect cycle in directed graph DFS (detectCycleDirected_dfs.cpp))
//will use this code (detectCycleDirected_dfs.cpp). As it's the same logic just 3-4 lines added in it
// beaucse the logic is exact same so we use the same concept of detection of loop and it's code


// Observations - 

// 1. Everyone who's part of the cycle and eveyone who has connected to cycle will never be safe nodes
// 2. eveyone who has connected to cycle - means if any node's outgoing edges is pointing to a node which is a part
//    of the cycle that node can also never be part of the safe node

// eveyone Apart from them (point 1&2) every other node can be safe node

//we nedd to figure out 2 things -
// A. which nodes are part of the cycle 
// B. which nodes are incoming to cycle (point 2)


bool dfs(int node, vector<int> adjLis[], vector<int> &vis, vector<int> &pathVis, vector<int> &check){
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for(auto it: adjLis[node]){
        if(!vis[it]){
            // we found the cycle
            if(dfs(it, adjLis, vis, pathVis, check) == true){
                check[node] = 0;
                return true;
            }
            
        }
        else if(pathVis[it] == 1){  // we found the cycle
            check[node] = 0;
            return true;
        }
    }

    // // we don't find cycle
    pathVis[node] = 0;
    check[node] = 1;
    return false; 
}
vector<int> eventualSafeNodes(int V, vector<int> adjLis[]) {
    
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    vector<int> safeNodes;
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, adjLis, vis, pathVis, check);
        }
    }
    for(int i = 0; i<V; i++){
        if(check[i] == 1) safeNodes.push_back(i);
    }
    return safeNodes;
}


// TC - O(V + E)        O(V + E) beacuse of directed graph and this what it takes for DFS in directed graph
// SC - O(V) + O(V) = O(3V) 

int main(){
     
    int n, m;
    cin >> n >> m;
    vector<int> adjLis[n]; // 0-based indexing

    // the entire graph has been stored here -  directed graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adjLis[u].push_back(v);
    }


    vector<int> res = eventualSafeNodes(n, adjLis);
    cout << "Safe nodes are " << endl;
    for(auto it: res) cout << it << " ";

} 


// 7 7
// 0 1
// 0 2
// 1 3
// 1 2
// 2 5
// 3 0
// 4 5


// 12 13
// 0 1
// 1 2
// 2 3 
// 3 4
// 3 5
// 4 6
// 5 6
// 6 7
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9