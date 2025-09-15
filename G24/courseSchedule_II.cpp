#include<bits/stdc++.h>
using namespace std;


// This problem boils downs to find whether the graph we have created using inputs is cyclic or not
// if it is cyclic that means it is not possible to Schedule all tasks
// if it is acyclic that means it is possible to Schedule all tasks

// Now we can solve this by either G-19 or G-22 way
// 1. Detect if this directed graph has a cycle or not. using DFS (G-19)
// 2. Detect if this directed graph has a cycle or not. using BFS which uses topo sort (G-23)


// but For 
// Course Schedule - II 
// for this they ask us for ordering 
// There for we solved this problem using BFS topo sort way
// But yes you can also use DFS way as well 


vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjLis(n);
    for(auto it: prerequisites){
        adjLis[it[1]].push_back(it[0]);
    }

    vector<int> indegree(n, 0);
    for(int node = 0; node < n; node ++){
        for(auto it: adjLis[node]){
            indegree[it] ++;
        }
    }

    queue<int> q;
    for(int node = 0; node < n; node ++){
        if(indegree[node] == 0) q.push(node);
    }

    vector<int> topoSort;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it: adjLis[node]){
            indegree[it] --;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topoSort.size() == n) return topoSort;
    else return {};
}




int main(){
    int n = 4;
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> res = findOrder(n, prerequisites);
    if(res.size() == n) {
        cout << "possible to schedule all the tasks" << endl;
        cout << "Here is the one of the order of tasks " << endl;
        for(auto it: res) cout << it << " ";
    }
    else cout << "Not possible to schedule all the tasks";
} 





// 1 0
// 2 1
// 3 2
// 1 2

// {{1, 0}, {2, 1}, {3, 2}, {1, 2}}
