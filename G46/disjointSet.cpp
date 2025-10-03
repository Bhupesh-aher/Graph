#include<bits/stdc++.h>
using namespace std;

// This template will help you to solve almost all the problems 
// This code will work both for 0 based and 1 based indexing graph
// that's why the size is taken is n + 1

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


// TC - O(4 alpha) = O(1)


int main(){
    
    int n =  7;             // No of nodes in graph
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // is 3 and 7 in the same component or not

    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "3 and 7 are in same component" << endl;
    }
    else cout << "3 and 7 are not in same component" << endl;

    ds.unionByRank(3, 7);
 
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "3 and 7 are in same component" << endl;
    }
    else cout << "3 and 7 are not in same component" << endl;


    


    // Note -  Don't use unionByRank and unionBySize toghther use any one at a time
    // Don't use both of them together



    // ds.unionBySize(1, 2);
    // ds.unionBySize(2, 3);
    // ds.unionBySize(4, 5);
    // ds.unionBySize(6, 7);
    // ds.unionBySize(5, 6);

    // // is 3 and 7 in the same component or not

    // if(ds.findUParent(3) == ds.findUParent(7)){
    //     cout << "3 and 7 are in same component" << endl;
    // }
    // else cout << "3 and 7 are not in same component" << endl;

    // ds.unionBySize(3, 7);
 
    // if(ds.findUParent(3) == ds.findUParent(7)){
    //     cout << "3 and 7 are in same component" << endl;
    // }
    // else cout << "3 and 7 are not in same component" << endl; 
}








