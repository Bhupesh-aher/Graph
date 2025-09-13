#include<bits/stdc++.h>
using namespace std;



vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};              // 0-based indexing

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
    vector<int> adjLis[n]; // 0-based indexing

    // the entire graph has been stored here -  directed graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adjLis[u].push_back(v);
    }


    vector<int> res = topoSort(n, adjLis);
    cout << "Topological sort for the given DAG " << endl;
    cout << "One of the linear ordering that we can get from gievn DAG is " << endl;
    for(auto it: res) cout << it << " ";

} 


// 6 6
// 5 0
// 5 2
// 4 1
// 4 0
// 2 3
// 3 1



