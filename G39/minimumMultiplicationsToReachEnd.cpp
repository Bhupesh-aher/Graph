#include<bits/stdc++.h>
using namespace std;


// Here we don't need PQ. Queue will work 
// You will get correct output using PQ but there is no need you can just use Queue 
// {steps, number}

int minimumMultiplications(vector<int> &arr, int start, int end){
    //       {stps, number}
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;       // // 10^5

    while(!q.empty()){
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        for(auto it: arr){
            int num = (node * it) % mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                q.push({steps + 1, num});
            }
        }
    }
    if(dist[end] == 1e9) return -1;
    return dist[end];
}


// At worst we will genrate 99999(10^5 = 100000) no of nodes
// and we are multiplies them with all arr elements 
// if look constraints arr is <= 10^4 so we won't genrate 10^5 numbers 
// so we cannpt predict the exact TC. It depends on given arr

// but you can say just TC = O(10000 * N) but this is just assumation not the exact. 
// Exact TC we can't predict

// N = arr.size()




int main(){
    int start = 3;
    int end = 30;        
    vector<int> arr = {2, 5, 7};

    int res = minimumMultiplications(arr, start, end);
    cout << "Minimum Multiplications To reach from " << start << " To " << end << " is " << res; 

}










