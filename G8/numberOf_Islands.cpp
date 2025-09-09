#include<bits/stdc++.h>
using namespace std;

//You can do this same thing using DFS as well
// the DFS code will be as it is which we have done in (dfs.cpp)
// just add the logic of traverse in the neighbours 

// solved using BFS

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in the neighbours and mark them visited if it's a land
        // in all 8 directions
        for(int delRow = -1; delRow <= 1; delRow ++){
            for(int delCol = -1; delCol <= 1; delCol ++){
                int nRow = delRow + row;
                int nCol = delCol + col;
                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int row = 0; row <n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt ++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

// TC - O(N^2) * 8
// SC - O(N^2) + O(N^2) // vis, queue

// queue - if all are 1's in grid. but it won't happens it is rare case 
// overall you can say that SC - O(N^2) 




// This below code is exaclty same as above code
// just the above code is for 8 directions and the below code is for 4 directions 
// so the code of traversing on neighbours slightly diff
// rest of the code remains same
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    int dRow[] = {-1, 0, +1, 0};
    int dCol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in the neighbours and mark them visited if it's a land
        // in all 4 directions
        
        for(int i = 0; i < 4; i ++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int row = 0; row <n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt ++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

// TC - O(N^2) * 4
// SC - O(N^2) + O(N^2) // vis, queue

// queue - if all are 1's in grid. but it won't happens it is rare case 
// overall you can say that SC - O(N^2) 








// solved using DFS
 
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    int n = grid.size();
    int m = grid[0].size();
    
    for(int i = 0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, grid);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int row = 0; row <n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt ++;
                dfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}



int main(){
    
    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};


    
    int res = numIslands(grid);
    cout << "Number of Islands " << res;
    
    
} 