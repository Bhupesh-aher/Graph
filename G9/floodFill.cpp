#include<bits/stdc++.h>
using namespace std;

//You can do this same thing using BFS as well
// the BFS code will be as it is which we have done in (bfs.cpp)
// just add the logic of traverse in the neighbours 

// solved using DFS

void dfs(int row , int col, vector<vector<int>>& ans, vector<vector<int>>& image, int iniColor, int newColor, int delRow[], int delCol[]){
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
            dfs(nrow, ncol, ans, image, iniColor, newColor, delRow, delCol);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // copying the image matrix to ans and then will return ans matrix as result 
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, iniColor, newColor, delRow, delCol);
    return ans;   
}

// X = N * M (total no of nodes)

// TC - O(X) + O(x * 4) = O(X) = O(N * M)
// SC - O(N * M) + O(N * M)   ans, auxillary space



int main(){
    
    vector<vector<int>> image = {
        {1, 1, 1},
        {2, 2, 0},
        {2, 2, 2}
    };
    int sr = 2;
    int sc = 0;
    int newColor = 3;

    vector<vector<int>> res = floodFill(image, sr, sc, newColor);

    cout << "modified image after performing the flood fill" << endl;
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }


    
    
    
} 