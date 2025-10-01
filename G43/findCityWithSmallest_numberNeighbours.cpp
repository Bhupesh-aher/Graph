#include<bits/stdc++.h>
using namespace std;

//  Find the City With the Smallest Number of Neighbours at a Threshold Distance


// We have used Floyd Warshall to solve this problem
// But this problem can also be done using Dijkstra algo as well 
// While using Dijkstra, compute dijkstra for every node (src node will be diff each time) (code - notes.txt G 42)



int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    for(auto it: edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for(int city = 0; city < n; city ++){
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity ++){
            if(dist[city][adjCity] <= distanceThreshold){
                cnt ++;
            }
        }
        if(cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}


int main(){
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 3, 4}, {1, 2, 1}, {3, 2, 1}};
    int distanceThreshold = 4;
    int res = findTheCity(n, edges, distanceThreshold);

    cout << "smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold " << res;

}





// This is the undirected graph represntation of edges in form of adjList

// 4 4
// 0 1 3
// 1 3 4
// 1 2 1
// 3 2 1







