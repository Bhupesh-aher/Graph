#include<bits/stdc++.h>
using namespace std;



vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V, 0); // 0-based indexing       

    for(int node = 0; node < V; node++){
        for(auto it: adj[node]){
            indegree[it] ++;
        }
    }

    queue<int> q;
    for(int node = 0; node < V; node++){
        if(indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it] --;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
    
}

// TC - O(V + E)        O(V + E) beacuse of directed graph and this what it takes for BFS in directed graph
// SC - O(V) + O(V) = O(2V) 


int main(){
     
    int n, m;
    cin >> n >> m;
    vector<int> adj[n]; // 0-based indexing

    // the entire graph has been stored here -  directed graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> TopoSort = topoSort(n, adj);

    if (TopoSort.size() == n) cout << "The graph has no cycle, as the topological sort is of size N";
    else  cout << "The graph has a cycle, as the topological sort is not of size N";
} 




// This graph has no cycle - notes G22
// 6 6
// 5 0
// 5 2
// 4 1
// 4 0
// 2 3
// 3 1
// output is = The graph has no cycle, as the topological sort is of size N









// just for the below test case i have written 1 based indexing implementation -

// This graph has a cycle - notes G23
// 5 5

// 1 2
// 2 3
// 3 4
// 3 5
// 4 2

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V + 1, 0); // 1-based indexing       

    for(int node = 1; node <= V; node++){
        for(auto it: adj[node]){
            indegree[it] ++;
        }
    }

    queue<int> q;
    for(int node = 1; node <= V; node++){
        if(indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it] --;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
    
}

// The output is = The graph has a cycle, as the topological sort is not of size N






// If we carefully see we don't need to store the topo sort we just need tht cout 
// so instead of storing topo just maintain cnt and at the end compare cnt with n


// int topoSort(int V, vector<int> adj[]){
//     vector<int> indegree(V, 0); // 1-based indexing       

//     for(int node = 0; node < V; node++){
//         for(auto it: adj[node]){
//             indegree[it] ++;
//         }
//     }

//     queue<int> q;
//     for(int node = 0; node < V; node++){
//         if(indegree[node] == 0) {
//             q.push(node);
//         }
//     }

//     int cnt = 0;
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         cnt ++;

//         for(auto it: adj[node]){
//             indegree[it] --;
//             if(indegree[it] == 0) q.push(it);
//         }
//     }
//     return cnt;
// }

// if (cnt == n) cout << "The graph has no cycle, as the topological sort is of size N";
// else  cout << "The graph has a cycle, as the topological sort is not of size N";

