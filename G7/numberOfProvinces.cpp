#include<bits/stdc++.h>
using namespace std;


// O(v + 2E)
void dfs(int node, vector<int> adjLis[], int vis[]) {
    vis[node] = 1;
    for(auto it: adjLis[node]){
        if(!vis[it]){
            dfs(it, adjLis, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V){
    vector<int> adjLis[V]; //0-based indexing

    // to change adj matrix to adj list
    for(int i = 0; i<V; i++){
        for(int j =0; j<V; j++){
            if(adj[i][j] == 1 && i != j){
                adjLis[i].push_back(j);
                adjLis[j].push_back(i);
            }
        }
    }
    int vis[V] = {0};
    int cnt = 0;
    for(int i = 0; i<V; i++){                   // O(N)
        if(!vis[i]){
            cnt ++;
            dfs(i, adjLis, vis);
        }
    }
    return cnt;

}

// TC - O(N) + O(v + 2E)
// SC - O(V) + O(N)             // vis, auxillary stack 
// where V = no of total nodes in whole graph (V == N)

int main(){
    
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int V = adj.size();

    int res = numProvinces(adj, V);
    cout << "Number of provinces: " << res << endl;
    
    
    
} 





// starting node = 1;
// input
// 8 8

// 1 2
// 1 3
// 2 5
// 2 6
// 3 7
// 3 4
// 7 8
// 4 8

