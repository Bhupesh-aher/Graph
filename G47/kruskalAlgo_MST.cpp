#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public: 
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


int MST(int V, vector<vector<int>> edges){

                // {wt, {u ,v}}
    vector<pair<int, pair<int, int>>> edgeList;
    for(auto it: edges){                                   // Creating an graph TC - O(N + E)
        edgeList.push_back({it[2], {it[0], it[1]}});
        edgeList.push_back({it[2], {it[1], it[0]}});
    }

    DisjointSet ds(V);
    sort(edgeList.begin(), edgeList.end());                       // TC - O(M log M) M = Total no of edges
    int sum = 0;
    vector<pair<int, int>> MST;

    for(auto it: edgeList){                                                  // O(M * 4 alpha)
        int wt =it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUParent(u) != ds.findUParent(v)){
            sum += wt;
            ds.unionBySize(u, v);           // in place unionBySize()  you can use unionByRank() as well
            MST.push_back({u, v});
        }
    }

    cout << "The MST is " << endl;
    for(auto it: MST) cout << it.first << " " << it.second << endl;
    return sum;
}


// TC - O (M log M) + (M * 4 alpha) 
// SC - O(2N) for DSU

int main(){
    
    int n = 6;
    vector<vector<int>> edges = {{1, 4, 1}, {1, 2, 2}, {1, 5, 4}, {2, 3, 3}, {2, 4, 3}, {2, 6, 7}, {3, 4, 5}, {3, 6, 8}, {4, 5, 9}};
    int res = MST(n, edges);

    cout << "The Sum of MST is " << res; 
    cout << endl;
}







// ⚠️ Optional Improvements (Style / Best Practices)
// 1. Avoid Duplicate Edges

// You're pushing both (u, v) and (v, u) into the edge list:

// adj.push_back({it[2], {it[0], it[1]}});
// adj.push_back({it[2], {it[1], it[0]}});


// ❌ Not needed for Kruskal's algorithm — it already treats the graph as undirected.

// ✅ Use just one push per edge:

// adj.push_back({it[2], {it[0], it[1]}});




