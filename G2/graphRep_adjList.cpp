#include<bits/stdc++.h>
using namespace std;



// undirected graph

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1-based indexing

    // the entire graph has been stored here -  undirected graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
} 

// // TC - O(m)
// // SC - O(2 * E)  
// // where E = means total no of edges (M)




// directed graph

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // 1-based indexing

    // the entire graph has been stored here -  directed graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
} 

// TC - O(m)
// SC - O(E)  
// E = m (edges)


// input for both above code 
// 5 6
// 1 2 
// 1 3 
// 2 4 
// 3 4 
// 2 5 
// 4 5 





// weighted undirected graph

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1]; // 1-based indexing

    // the entire graph has been stored here -  weighted undirected graph
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Directed edge u → v with weight w
        adj[v].push_back({u, w});  // Directed edge v → u with weight w

    }
    
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto it : adj[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }
    
} 


// TC - O(m)
// SC - O(2 * E)  
// E = m (edges)


// input 
// 5 6
// 1 2 2
// 1 3 3
// 2 4 1
// 3 4 4
// 2 5 6
// 4 5 3









// weighted directed graph

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1]; // 1-based indexing

    // the entire graph has been stored here -  weighted directed graph
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Directed edge u → v with weight w

    }
    
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto it : adj[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }
    
} 


// TC - O(m)
// SC - O(E)  
// E = m (edges)