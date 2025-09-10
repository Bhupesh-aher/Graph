#include<bits/stdc++.h>
using namespace std;


// Distance of nearest cell having 1 | 0/1 Matrix
// these both questions are same just 
// this Distance of nearest cell having 1 was about nearest 1 
// and this 0/1 Matrix was about nearest 0
// The code we have wrote is for nearest cell having 1
// just litile changes and it will work for 0/1 Matrix as well 



vector<vector<int>> nearest(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    //            {{row, col}, steps}
    queue<pair<pair<int, int>, int>> q;

    // n * m
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    // n * m * 4
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}

// TC - O(n * m) * 4
// SC - O 3(n * m)          // vis, dist, queue


int main(){
     
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 1}
    };
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> res = nearest(grid);

   for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
} 


// {0, 0, 0},
// {0, 1, 0},
// {1, 0, 0}