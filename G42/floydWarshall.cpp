#include<bits/stdc++.h>
using namespace std;

// The graph is represented as an adjacency matrix, and the matrix denotes the weight of the edges (if it exists) else -1

void shortestDistance(vector<vector<int>> &adjMatrix){
    int n = adjMatrix.size();

    // we can avoid this step as it just for ease of understanding
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adjMatrix[i][j] == -1){
                adjMatrix[i][j] = 1e9;
            }
            if(i == j) adjMatrix[i][j] = 0;
        }
    }

    // This is the main logic of Floyd Warshall Algorithm
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    // again this step is just to put -1 back which change to 1e9
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adjMatrix[i][j] == 1e9){
                adjMatrix[i][j] = -1;
            }
        }
    }
}




// For checking if negative cycle exist or not just add one conditon
void shortestDistance(vector<vector<int>> &adjMatrix){
    int n = adjMatrix.size();

    // we can avoid this step as it just for ease of understanding
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adjMatrix[i][j] == -1){
                adjMatrix[i][j] = 1e9;
            }
            if(i == j) adjMatrix[i][j] = 0;
        }
    }

    // This is the main logic of Floyd Warshall Algorithm
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    // This is the condition to check for negative cycle
    
    for(int i = 0; i < n; i++){
        if(adjMatrix[i][i]  < 0) cout << "Negative cycle exist";
    }

    // again this step is just to put -1 back which change to 1e9
    // which means it is not reachable even after trying via different paths
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adjMatrix[i][j] == 1e9){
                adjMatrix[i][j] = -1;
            }
        }
    }
}




// TC - O(N ^ 3)
// SC - O(N * N) 




int main(){
    vector<vector<int>> adjMatrix = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, -1},
        {3, 5, 4, 0}
    };

    // -1 means 1e9
    shortestDistance(adjMatrix);

    for(int i = 0; i < adjMatrix.size(); i++){
        for(int j = 0; j < adjMatrix.size(); j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

}


// This is the graph and above adjMatrix is representation of it 

// 4 6
// 0 1 2
// 1 0 1
// 1 2 3
// 3 0 3
// 3 1 5
// 3 2 4







