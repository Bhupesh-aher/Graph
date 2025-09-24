#include<bits/stdc++.h>
using namespace std;


// we can solve this problem using Dijkstar's algo
// beacuse we need minimum path means shortest path 
// src and dest is also mention is problem so that means we can solve this using Dijkstar's algo 

bool verify(int row, int col, int n, int m){
    return row >= 0 && row < n && col >= 0 && col < m;
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    // {diff, {row, col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row == n - 1 && col == m - 1) return diff;

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(verify(nrow, ncol, n, m)){
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return -1;
}

// TC - O(E log V) 

// E = n * m cells (Total no of edges) = n * m * 4
// 4 = every cell is connected to 4 directions (top, bottom, left, right)
// V = Total no of nodes
// how many nodes are there ? => Total no of cells = n * m

// n * m * 4 * log(n * m)




int main(){
    vector<vector<int>> grid = {
    {1, 2, 2},
    {3, 8, 2},
    {5, 3, 5}};

    
    int res = minimumEffortPath(grid);
    cout << "Path with Minumum Effort is " << res; 
} 




// vector<vector<int>> grid = {
//     {1, 2, 1, 1, 1},
//     {1, 2, 1, 2, 1},
//     {1, 2, 1, 2, 1},
//     {1, 1, 1, 2, 1}};
// Min path = 0


