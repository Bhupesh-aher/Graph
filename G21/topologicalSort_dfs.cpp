#include<bits/stdc++.h>
using namespace std;



bool dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
     vis[node] = 1;
     for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
     }
     st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    
    int vis[V] = {0}; // 0-based indexing
    stack<int> st;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


// TC - O(V + E)        O(V + E) beacuse of directed graph and this what it takes for DFS in directed graph
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



