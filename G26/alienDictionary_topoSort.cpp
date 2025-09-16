#include<bits/stdc++.h>
using namespace std;

// (G-22)
vector<int> topoSort(int V, vector<int> adjLis[]){
    int indegree[V] = {0};
    for(int node = 0; node < V; node++){
        for(auto it: adjLis[node]){
            indegree[it] ++;
        }
    }

    queue<int> q;
    for(int node = 0; node < V; node ++){
        if(indegree[node] == 0) q.push(node);
    }

    vector<int> topoSort;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);

        for(auto it: adjLis[node]){
            indegree[it] --;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topoSort;
}

// Multiple ans are possible

string findOrder(vector<string> dict, int n, int k){
    vector<int> adjLis[k];
    for(int i = 0; i < n - 1; i ++){
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for(int ptr = 0; ptr < len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adjLis[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(k, adjLis);
    string ans = "";
    for(auto it: topo){
        ans  += char(it + 'a');                 // + 'a' to get the character back
    }
    return ans;
    
}

int main(){
     
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int n = dict.size();
    int k = 4;
    string res = findOrder(dict, n, k);
    cout << "One of the ordering is  " << res;
} 




// When the ordering is not possible ?

// Test Case 1 
// abcd 
// abc 

// when larger string is before short string and all characters are matching 
// then the order is wrong

// if it would have been 
// abc 
// abcd
// in this case abc is before abcd and that's correct ordering in alien and english dict as well


// Test Case 2

// abc 
// bat 
// ade 

// in this case a -> b -> a 
// this is cyclic dependencies


// These are 2 test cases where dict is wrong 
// Beaucse we know if there is cycle topo sort is not possible