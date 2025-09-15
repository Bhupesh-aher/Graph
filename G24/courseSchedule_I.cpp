#include<bits/stdc++.h>
using namespace std;


// This problem boils downs to find whether the graph we have created using inputs is cyclic or not
// if it is cyclic that means it is not possible to Schedule all tasks
// if it is acyclic that means it is possible to Schedule all tasks

// Now we can solve this by either G-19 or G-22 way
// 1. Detect if this directed graph has a cycle or not. using DFS (G-19)
// 2. Detect if this directed graph has a cycle or not. using BFS which uses topo sort (G-23)


// For 
// Course Schedule - I 
// You can choose any way to solve the Course Schedule - I. 
// is it possible or not

// but For 
// Course Schedule - II 
// for this they ask us for ordering 
// There for we solved this problem using BFS topo sort way
// But yes you can also use DFS way as well 



bool canFinish(int n, vector<vector<int>>& prerequisites) {
    // created a directed graph
    vector<vector<int>> adjLis(n);
    for(auto it: prerequisites){
        adjLis[it[0]].push_back(it[1]);
    }

    vector<int> indegree(n, 0);
    for(int node = 0; node < n; node++){
        for(auto it: adjLis[node]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int node = 0; node < n; node++){
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
    if(topoSort.size() == n) return true; // possible to schedule all the tasks, because graph has no cycle (DAG)
    else return false;                    // not possible to schedule all the tasks, because graph has the cycle
}

int main(){
    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    int res = canFinish(n, prerequisites);
    if(res == 1) cout << "possible to schedule all the tasks";
    else cout << "Not possible to schedule all the tasks";
} 


// 0 1
// 1 2
// 2 3
// 2 1

// {{0, 1}, {1, 2}, {2, 3}, {2, 1}}
