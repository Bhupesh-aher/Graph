#include<bits/stdc++.h>
using namespace std;


// We don't need PQ we can just use Queue as well
// even if you use PQ it will be correct but there is no need 
// because stops are increasing by + 1 at every step so even if take queue it will be in increasing way (in ascending order)

// Increase is constatnt that's why there is no need to use PQ
// We have use Queue in previous problem as well where no need to take the PQ

// For more clearity dry run the code 

// usually we use queue {dist, {node, stops}} but this won't work if you dry run you will understand
// that's why we take {stops, {node, dist}} because for this problem stops is the condition which is the main factor not the dist (cost)
// first priority of judgment will be stops and then dist i can just keep on comparing all the distances and store it just the way we do usually
// we use dist in exact same way as we are doing till now as dist is our first priority to check. Till previous problem
// for this problem just beacuse stops is the main factor so will place stops as first in our queue structure {stops, {node, dist}} and not like this {dist, {node, stops}} which we do usually









int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adjLis(n);
    for(auto it: flights){
        adjLis[it[0]].push_back({it[1], it[2]});        // directed graph
    }

    //        {stops, {node, dist}}
    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int dis = it.second.second;

        if(stops > k) continue;

        for(auto it: adjLis[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                q.push({stops + 1, {adjNode, dis + edgeWeight}});
            }
        }
    }
    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}

// TC - O(E) 
// E = Total No of edges
// For this problem E iss flights.size()


int main(){
    int n = 5;
    //                         {from, to, cost}
    vector<vector<int>> flights = {{0, 1, 5}, {0, 3, 2}, {1, 2, 5}, {1, 4, 1}, {3, 1, 2}, {4, 2, 1}};
    int src = 0;
    int dst = 2;
    int k = 2;  // no of stops

    int res = findCheapestPrice(n, flights, src, dst, k);
    cout << "Chepest flight from " << src << " To " << dst << " Within K stops is " << res;
} 







// int n = 4;                  {from, to, cost}
// vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
// int src = 0;
// int dst = 3;
// int k = 1;  // no of stops




