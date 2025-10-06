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
    return row >=0 && row < n && col >=0 && col < m;
}

vector<int> numberOfIslands(int n, int m, vector<vector<int>> &operators){
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;
    vector<int> ans;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    for(auto it: operators){
        int row = it[0];
        int col = it[1];
        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt ++;
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(isValid(nrow, ncol, n, m)){
                if(vis[nrow][ncol] == 1){
                    int nodeNo = (row * m) + col;
                    int adjNodeNo = (nrow * m) + ncol;
                    if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                        cnt --;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}



int main(){
    int n = 4;
    int m = 5;

    vector<vector<int>> operators = {{0, 0}, {0,  0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};
    vector<int> res = numberOfIslands(n, m, operators);

    for(auto it: res) cout << it << " ";
    
} 