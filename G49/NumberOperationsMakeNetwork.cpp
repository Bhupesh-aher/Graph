#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public: 
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <=n; i++){
            parent[i] = i;
            size[i] = 1;
        } 
       
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] =  findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    } 
};



// Number of Operations to Make Network Connected 

int makeConnected(int n, vector<vector<int>>& edges) {
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        if(ds.findUParent(u) == ds.findUParent(v)){
            extraEdges++;
        }
        else {
            ds.unionBySize(u, v);
        }
    }
    int totalComponents = 0;
    for(int i = 0; i <n; i++){
        if(ds.parent[i] == i) totalComponents++;
    }
    int ans = totalComponents - 1;
    if(extraEdges >= ans) return ans;
    else return -1;
}



int main(){
    
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

    int res = makeConnected(n, edges);

    cout << "Minimum no of edges required to connect every components is " << res;
    
} 




