#include<bits/stdc++.h>
using namespace std;

// Find the No of Strongly Connected Components (SCC)

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adj2[]){
    vis[node] = 1;
    for(auto it: adj2[node]){
        if(!vis[it]){
            dfs2(it, vis, adj2);
        }
    }
}

int SCC(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    stack<int> st;

    // step 1                               O(V + E)
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }

    // step 2 - Reverse the graph (edges)               O(V + E)

    vector<int> adj2[V];                     // new adjList
    for(int i = 0; i <V; i++){
        vis[i] = 0;                  // vis can be resued in step 3 that's why this line
        for(auto it: adj[i]){       // i -> it we need to reverse it to it -> i
            adj2[it].push_back(i);
        }
    }

    // step 3                           O(V + E)
    int sccCnt = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            sccCnt++;
            dfs2(node, vis, adj2);
        }

    }

    return sccCnt;
}




// TC - O(3 * (V + E))
// SC - O(2V) + O(V + E) 
//     vis, st    adj2



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n]; // 0 based indexing

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    int res = SCC(n, adj);

    cout << "No of Strongly Connected Component is " << res;
    
} 

// n m 
// 8 10

// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 4 5
// 4 7
// 5 6
// 6 4
// 6 7