#include<bits/stdc++.h>
using namespace std;



// WE can solved this problem using Dijkstra's priority queue or set method
// but there is no need do that way. As when we traverse through matrix
// we realize that even if just use queue it will store all dist in ascending order
// beacuse we are moving by +1 at every step
// yeah if at evry step the dist we are taking is different in that case priority queue hepls
// beacuse it gives minimum at every iteration
// but for this problem there is no need to it
// so simple BFS queue method works efficiently - just dry run and observe the queue how it store in increasing order 
// no need of Dijkstra's priority queue. but yes ijkstra's priority queue will also work
// you can try it out you will get coreect output


int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dest){
    int n = grid.size();
    int m = grid[0].size();
            // dist      row col 
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int> (m, 1e9));

    dist[src.first][src.second] = 0;
    q.push({0, {src.first, src.second}});

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row == dest.first && col == dest.second) return dis;

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1){
                if(dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
    }
    return -1;
}


int main(){
    vector<vector<int>> grid = {
    {1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {1, 0, 0, 0}};

    pair<int, int> src = {0, 1};
    pair<int, int> dest = {2, 2};
    // 0,1 2,2


    int res = shortestPath(grid, src, dest);
    cout << "Shortest path in binary maze is " << res;
} 







