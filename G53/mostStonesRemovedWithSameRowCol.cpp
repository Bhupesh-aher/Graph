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



int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();         // Total no of stones
    int maxRow = 0;
    int maxCol = 0;
    for(auto it: stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);   // +1 just to be safe

    unordered_map<int, int> stoneNodes;
    for(auto it: stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;                // Total no of connected components
    for(auto it: stoneNodes){
        if(ds.findUParent(it.first) == it.first){
            cnt ++;
        }
    }
    return n - cnt;
}


// ans = total no of stones - Total no of connected components  



int main(){
    vector<vector<int>> stones = {{0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}};
    int res = removeStones(stones);

    cout << " Largest number of stones that can be removed is " << res;
    
} 