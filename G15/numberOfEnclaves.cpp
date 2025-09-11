#include<bits/stdc++.h>
using namespace std;

// Number of Enclaves this problem is same as previous problem (Surrounded Regions | Replace O's with X's)

// We have done this using BFS but we can also do it using DFS as well
// As long as we are starting from a boundaries and marking all of those guys who are connected to '1'

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                vis[nrow][ncol]  = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    // traverse first and last row
    for(int j = 0; j < m; j++){
        // first row
        if(!vis[0][j] && grid[0][j] == 1){
            bfs(0, j, vis, grid, delrow, delcol);
        }
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 1){
            bfs(n-1, j, vis, grid, delrow, delcol);
        }
    }

    // traverse first and last col
    for(int i = 0; i<n; i++){
        // first col
        if(!vis[i][0] && grid[i][0] == 1){
            bfs(i, 0, vis, grid, delrow, delcol);
        }

        // last col 
        if(!vis[i][m-1] && grid[i][m-1] == 1){
            bfs(i, m-1, vis, grid, delrow, delcol);
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt ++;
            }
        }
    }
    return cnt;
}
// In this bfs we start taking boundary 1 and call the bfs every time
// another way is to traverse the boundary and put all 1's who are at boundary in the queue and then call bfs only once
// this is called as Multisource bfs (means we start with more than 1 start points [we started with multiple starting points]) 
// we usually start bfs with only 1 single start point (bfs.cpp). Here we will start with more than 1 start points that's why it is called as Multisource bfs
// you can do this in this problem as well multi source bfs(Surrounded Regions | Replace O's with X's). As i haven't wrote that code. i have wrote bfs but not multisource rather our regular single start point and that approach is also accpeted
// the code is below for this -

// just write it in more crisp way. logic is same as above code and the below code(dfs). just write it in more clean way

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            // another way to trvaerse the boundries
            // 1st row    1st col    last row     last col
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                vis[nrow][ncol]  = 1;
                q.push({nrow, ncol});
            }
        }
    }


    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt ++;
            }
        }
    }
    return cnt;
}




// In case you want DFS code here it is - 

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, vis, grid, delrow, delcol);
        }
    }

}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    // traverse first and last row
    for(int j = 0; j < m; j++){
        // first row
        if(!vis[0][j] && grid[0][j] == 1){
            dfs(0, j, vis, grid, delrow, delcol);
        }
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 1){
            dfs(n-1, j, vis, grid, delrow, delcol);
        }
    }

    // traverse first and last col
    for(int i = 0; i<n; i++){
        // first col
        if(!vis[i][0] && grid[i][0] == 1){
            dfs(i, 0, vis, grid, delrow, delcol);
        }

        // last col 
        if(!vis[i][m-1] && grid[i][m-1] == 1){
            dfs(i, m-1, vis, grid, delrow, delcol);
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt ++;
            }
        }
    }
    return cnt;
}



// TC - + O(N * M) + O(N * M) * 4 = O(N * M)
// SC - O(N * M) + O(N * M) = O(N * M) 
//       vis      auxillary/dfs (depending upon whether you use BFS or DFS)

int main(){
     
    vector<vector<int>> grid = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    

    int n = grid.size();
    int m = grid[0].size();

    int res = numEnclaves(grid);
    cout << "Number of Enclaves " << res;
} 