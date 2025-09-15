#include<bits/stdc++.h>
using namespace std;

// We have already solved this problem in (G-20)
// In that solved using cycle detection technique which we learn in (detect cycle in directed graph DFS (detectCycleDirected_dfs.cpp))

// Here we have solved that by using BFS Topo Sort exacxt thing which we have learn in (G-22)
// just before doing an BFS topo sort we reverse the graph (by reversing the edges) and at the end just sort the safeNodes
// apart from these 2 things the code and logic everything is same just like we are doing in (G-22)

vector<int> eventualSafeNodes(vector<vector<int>>& adjLis) {
    int V = adjLis.size();
    vector<vector<int>> adjReverseLis(V);
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        // i -> it reverse the edge to  it -> i
        for(auto it: adjLis[i]){
            adjReverseLis[it].push_back(i);
            indegree[i] ++;
        }
    }

    queue<int> q;
    for(int i = 0; i< V; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> safeNodes;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjReverseLis[node]){
            indegree[it] --;
            if(indegree[it] == 0) q.push(it);
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}




// TC - O(V + E) + O(N log N)     O(V + E) beacuse of directed graph and this what it takes for DFS in directed graph
// SC - O(V) + O(V) = O(3V) 

int main(){
     
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLis(n); 

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjLis[u].push_back(v);
    }


    vector<int> res = eventualSafeNodes(adjLis);
    cout << "Safe nodes are " << endl;
    for(auto it: res) cout << it << " ";

} 


// 7 7
// 0 1
// 0 2
// 1 3
// 1 2
// 2 5
// 3 0
// 4 5


// 12 13
// 0 1
// 1 2
// 2 3 
// 3 4
// 3 5
// 4 6
// 5 6
// 6 7
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9

