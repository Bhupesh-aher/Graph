#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int V, vector<pair<int, int>> adj[]){

        //   dist node
    set<pair<int, int>> st;
    int src = 0;
    vector<int> dist(V);
    for(int i = 0; i < V; i++) dist[i] = 1e9;
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()){
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < dist[adjNode]){

                // erasing from set if dist[adjNode] is not eqaul to 1e9
                // that means it was previosuly visited already so we can erase it from the set

                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});

            }
        }    
    }
    return dist;
    

}

// TC - O(E log V)
// E = total no of edges
// V = no of nodes



int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n]; // 0-based indexing

    // the entire graph has been stored here -  weighted directed graph
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Directed edge u → v with weight w

    }
    
    vector<int> res = dijkstra(n, adj);

    cout << "The shortest dist from src node to other nodes are" << endl; 

    for(auto it: res) cout << it << " ";
} 





// *(st.begin())
// (st.begin()) - is iterator pointing to the address where the sets first element is
// * will give the value 


// Input
// n m
// 6 8
// 0 1 4
// 0 2 4 
// 1 2 2
// 2 3 3 
// 2 4 1
// 2 5 6
// 3 5 2
// 4 5 3

// u - > v with wt

