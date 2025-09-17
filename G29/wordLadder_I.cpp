#include<bits/stdc++.h>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);
    // O(N)
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        // O(word.length * 26)
        for(int i = 0; i < word.size(); i++){
            char originalChar = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // Transformed word exists in the set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = originalChar;
        }
    }
    return 0;
}



// TC -  O(N * word.length * 26 * log N)    
// SC - O(N) + O(N) queue, st


int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int res = ladderLength(beginWord, endWord, wordList);
    cout << res;
} 


