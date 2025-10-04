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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    unordered_map<string, int> mapMailToNode;
    DisjointSet ds(n);
    for(int i = 0; i < n; i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string mail = accounts[i][j];
            if(mapMailToNode.find(mail) == mapMailToNode.end()){
                mapMailToNode[mail] = i;
            }
            else {
                ds.unionBySize(i, mapMailToNode[mail]);
            }
        }
    }
    vector<vector<string>> mergeMail(n);
    for(auto it: mapMailToNode){
        string mail = it.first;
        int node = ds.findUParent(it.second);
        mergeMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for(int i = 0; i < n; i++){
        if(mergeMail[i].size() == 0) continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it: mergeMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}




int main(){
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    vector<vector<string>> result = accountsMerge(accounts);

    // Print the result
    for (const auto& account : result) {
        for (const auto& item : account) {
            cout << item << " ";
        }
        cout << endl;
    }
    
} 