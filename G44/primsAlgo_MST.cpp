#include<bits/stdc++.h>
using namespace std;


// Just to find sum this is the code
int mstSum(int V, vector<vector<int>> &edges){

    // Convert edge list to adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for(auto it: edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);
    //     {wt, node}
    pq.push({0, 0});
    int sum = 0;

    // O(E)
    while(!pq.empty()){
        auto it = pq.top();             // O(log E)
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if(visited[node] == 1) continue;        // Already vistited no need to go furhter. Go directly to next iteration, beacuse this node is already a part of the MST

        visited[node] = 1;
        sum += wt;

        for(auto it: adj[node]){                // O(E)
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(!visited[adjNode]){
                pq.push({edgeWeight, adjNode});        // O(log E)
            }
        }
    }
    return sum;
}

// TC - O(E log E) + O(E log E) = O(E log E) 


// To get MST edges
vector<pair<int, int>> mst(int V, vector<vector<int>> &edges){

    // Convert edge list to adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for(auto it: edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<int> visited(V, 0);
    //     {wt, {node, parent}}
    pq.push({0, {0, -1}});
    int sum = 0;
    vector<pair<int, int>> MST;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(visited[node] == 1) continue;

        if(parent != -1) {
            MST.push_back({parent, node});  
        }
        visited[node]= 1;
        sum += wt;

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(!visited[adjNode]){
                pq.push({edgeWeight, {adjNode, node}});
            }
        }
    }
    return MST;
}


// To Get MST this is the code





// No differece in both code it's just 1st code is if you want just the sum 
// so you won't store the mst tha's why pq will store only {wt, node}

// in case you want MST as well then code 2 is for you 
// PQ will store this time {wt, {node, parent}} as we want the parent as well to store the edge
// just declare MST arr and add when we pop out from PQ


int main(){
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 4, 2}, {2, 3, 2}, {3, 4, 1}};
    

    int res = mstSum(n, edges);
    cout << "The Sum of MST is " << res; 
    cout << endl;


    vector<pair<int, int>> MSTEdges = mst(n, edges);

    for(auto it: MSTEdges){
        cout << it.first << " " << it.second;
        cout << endl;
    }

}





// This is the undirected graph represntation of edges in form of adjList

// 5 6
// 0 1 2
// 0 2 1
// 1 2 1
// 2 4 2
// 2 3 2
// 3 4 1







