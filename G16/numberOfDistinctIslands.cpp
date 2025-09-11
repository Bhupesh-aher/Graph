#include<bits/stdc++.h>
using namespace std;

// We have done this using DFS but we can also do it using BFS as well

// O(N * M) * 4
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0){
    vis[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    int n = grid.size();
    int m = grid[0].size();

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    for(int i = 0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;


    for(int i = 0; i< n; i++){          // O(N * M) * log(set length)
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

// TC - O(N * M) * log(set length) + O(N * M) * 4             = O(N * M)
// set lenght is = N * M (At max it will store all the grid cell)

// SC - O(N * M) + O(N * M) + O(N * M)      = O(N * M)
//        vis        set    auxiliary space

int main(){
     
    vector<vector<int>> grid = {
        {1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 0, 1}
    };

    int res = countDistinctIslands(grid);
    cout << "Number of Distinct Islands is " << res;
} 



// {1, 0, 0, 1, 1},
// {1, 1, 0, 0, 0},
// {0, 0, 0, 1, 0},
// {1, 1, 0, 1, 1}

// res = 3