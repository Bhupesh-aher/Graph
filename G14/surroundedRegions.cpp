#include<bits/stdc++.h>
using namespace std;


// We have done this using DFS but we can also do it using BFS as well
// As long as we are starting from a boundaries and marking all of those guys who are connected to 'O'

// O(N * M) * 4
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid, int delRow[], int delCol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
            dfs(nrow, ncol, vis, grid, delRow, delCol);
        }
    }
}

void solve(vector<vector<char>>& grid) {
    // n - row, m - col
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    
    // Traverse first and last row
    for(int j = 0; j<m; j++){                   // O(M)
        // first row
        if(!vis[0][j] && grid[0][j] == 'O'){
            dfs(0, j, vis, grid, delRow, delCol);
        }
        
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 'O'){
            dfs(n-1, j, vis, grid, delRow, delCol);
        }
    }

    // Traverse first and last col
    for(int i = 0; i<n; i++){                   // O(N)
        // first col
        if(!vis[i][0] && grid[i][0] == 'O'){
            dfs(i, 0, vis, grid, delRow, delCol);
        }

        // last col
        if(!vis[i][m-1] && grid[i][m-1] == 'O'){
            dfs(i, m-1, vis, grid, delRow, delCol);
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
}

// TC - O(N) + O(M) + O(N * M) * 4  = O(N * M) 
// SC - O(N * M) + O(N * M)         = O(N * M)    
//        vis,  auxiliary space


// In case you want BFS code here it is - 

 void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid, int delRow[], int delCol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});

            }
        }
    }
}
// n - row, m - col
void solve(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    // Traverse first and last row
    for(int j = 0; j<m; j++){
        // first row
        if(!vis[0][j] && grid[0][j] == 'O'){
            bfs(0, j, vis, grid, delRow, delCol);
        }
        
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 'O'){
            bfs(n-1, j, vis, grid, delRow, delCol);
        }
    }

    // Traverse first and last col
    for(int i = 0; i<n; i++){
        // first col
        if(!vis[i][0] && grid[i][0] == 'O'){
            bfs(i, 0, vis, grid, delRow, delCol);
        }

        // last col
        if(!vis[i][m-1] && grid[i][m-1] == 'O'){
            bfs(i, m-1, vis, grid, delRow, delCol);
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
}

int main(){
     
    vector<vector<char>> grid = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'O', 'X', 'X', 'X'}
    };

    solve(grid);

    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

} 