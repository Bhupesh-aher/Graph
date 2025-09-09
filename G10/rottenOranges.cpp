#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];
    // {{row, col}, t}
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && vis[i][j] != 2){
                return -1;
            }
        }
    }
    return tm;
}

// TC - O(n * m) + O(n * m) * 4  = O(n * m)
// SC - O(n * m)  visited matrix, queue. 

// The above codes works perfect
// but in case if want remove the last loop for checking -1 
// you can refer below code
// everything is same just the last loop is removed and added 2 count variables
// the core logic remains same

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];
    // {{row, col}, t}
    queue<pair<pair<int, int>, int>> q;
    int cntFresh = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
            if(grid[i][j] == 1) cntFresh ++;
        }
    }

    int tm = 0;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int cnt = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
                cnt ++;
            }
        }
    }
    
    if(cnt != cntFresh) return -1;
    return tm;
}




int main(){
    
    vector<vector<int>> grid = {
        {0, 1, 2},
        {0, 1, 1},
        {2, 1, 1}
    };

    int res = orangesRotting(grid);
    if(res != -1) cout << "Minimum time to rotten all oranges is " << res;
    else cout << "Not possible to rotate all oranges";
    
    
    
} 