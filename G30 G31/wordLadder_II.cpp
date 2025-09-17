#include<bits/stdc++.h>
using namespace std;


// G-30
// This solution will give you TLE on Leetcode beacuse of strict constraints
// To successfuly submit on LeetCode we need lot of optimization just like we do in CP(competitive programming)
// But this particular solution is gonna work absolutely fine in interviews

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();

        // Erase all words that has been
        // used in the previous levels to transform
        if(vec.size() > level){
            level ++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        string word = vec.back();
        // store the ans
        if(word == endWord){
            // the first sequence where we reached the endWord
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }


        for(int i = 0; i < word.size(); i++){
            char originalChar = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = originalChar;
        }
    }
    return ans;
}

// TC - We can't predict a TC for this solution beacuse it is next to impoosible 
// it will vary from example to example

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>>  res = findLadders(beginWord, endWord, wordList);
    
    for(auto it: res){
        for(auto str: it){
            cout << str << " ";
        }
        cout << endl;
    }
} 


// string beginWord = "bat";
// string endWord = "coz";
// vector<string> wordList = {"pat","bot","pot","poz","coz"};