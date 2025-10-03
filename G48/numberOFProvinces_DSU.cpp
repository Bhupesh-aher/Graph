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


// We have solved this problem in (G - 7)
// here we are solving using Disjoint set so that we get more comfrotable with Disjoint set 

 int numProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adjList(n + 1);
    DisjointSet ds(n);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(isConnected[i-1][j-1] == 1 && i != j){
                ds.unionBySize(i, j);
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <=n; i++){
        if(ds.findUParent(i) == i) cnt ++;
    }
    return cnt;
}



int main(){
    
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int res = numProvinces(adj);
    cout << "Number of provinces: " << res << endl;
    
} 





// class DisjointSet {
// public: 
//     vector<int> rank, parent, size;
//     DisjointSet(int n){
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for(int i = 0; i <=n; i++){
//             parent[i] = i;
//             size[i] = 1;
//         } 
       
//     }

// for(int i = 1; i <=n; i++){
//      if(ds.parent[i] == i) cnt ++;
// }


// You can directly use parent[] arr as well just declare them in public so that we can access them from outside