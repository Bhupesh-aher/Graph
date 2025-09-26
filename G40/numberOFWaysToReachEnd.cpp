#include<bits/stdc++.h>
using namespace std;



int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adjLis(n);
    for(auto it: roads){
        adjLis[it[0]].push_back({it[1], it[2]});
        adjLis[it[1]].push_back({it[0], it[2]});
    }               
                    // {dist, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    int mod = (int)(1e9 + 7);

    while(!pq.empty()){
        long long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adjLis[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dis + edgeWeight, adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + edgeWeight == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1] % mod;        
}


// TC - O(E log V)


int main(){
    int n = 7;
    //                         {from, to, time}
    vector<vector<int>> roads = {{0, 4, 5}, {0, 1, 2}, {0, 6, 7}, {1, 2, 3}, {1, 3, 3}, {4, 6, 2}, {2, 5, 1}, {3, 6, 3}, {3, 5, 1}, {6, 5, 1}};
    

    int res = countPaths(n, roads);
    cout << "Number of Ways You can arrive at destination in the shortest amount of time is  " << res;

}





// n m 
// 7 10
// 0 4 5
// 0 1 2
// 0 6 7
// 1 2 3 
// 1 3 3 
// 4 6 2
// 2 5 1
// 3 6 3
// 3 5 1
// 6 5 1


// src = 0 and dst = n  always 
// For above example
// src = 0 dst = 6
// shortest path from src to dst value is = 7

// 0 -> 6
// 0 -> 4 -> 6
// 0 -> 1 -> 2 -> 5 -> 6
// 0 -> 1 -> 3 -> 5 -> 6

// All these paths gives shortest distance 7
// there 4 paths. Means 4 ways reach end(dst) with shortest distance 
// No of shortest path is = 4
// we need to tell how many paths are there which are shortest this is the question

// 0 -> 1 -> 3 -> 6 This also one path but this gives 8 as distance which is not short








