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


bool isValid(int row, int col, int n, int m){
    return row >= 0 && row < n && col >= 0 && col < n;
}
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    // step 1
    for(int row = 0; row < n; row ++){
        for(int col = 0; col < n; col ++){
            if(grid[row][col] == 0) continue;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                    int nodeNo = (row * n) + col;
                    int adjNodeNo = (nrow * n) + ncol;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;
    for(int row = 0; row < n; row ++){
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 1) continue;
            set<int> components;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                    int adjNodeNo = (nrow * n) + ncol;
                    components.insert(ds.findUParent(adjNodeNo));
                }
            }
            int sizeTotal = 0;
            for(auto it: components){
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    // In case all cells in grid is 1
    for(int cellNo = 0; cellNo < n * n; cellNo++){
        mx = max(mx, ds.size[ds.findUParent(cellNo)]);
    }
    return mx;
}



int main(){
    int n = 4;
    int m = 5;

    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    int res = largestIsland(grid);
    cout << "The size of the largest island in grid is " << res;
    
} 