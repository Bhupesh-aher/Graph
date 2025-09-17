#include<bits/stdc++.h>
using namespace std;


// We solved this problem and that (wordLadder_II  G-30) particular solution is gonna work absolutely fine in interviews
// But it was giving TLE on Leetcode
// so to submit on leetcode this is the code below

// Note - If you are just prerparing for interviews you can skip this code and approach as it of no use interviews
// The G-30 is approach and code is for interviews

// we will use hack which we use in CP 
// don't do this hack in interviews
// so we are going to use CP way 
// we are not going to write the code in interview way like in interviews we don't use global variable 
// but here we will use declare lot of things in globally as we are using CP way







class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
private: 
    void dfs(string word, vector<string> &seq){
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i = 0; i < word.size(); i++){
            char originalChar = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = originalChar;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        int sz = beginWord.size();
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0; i < sz; i++){
                char originalChar = word[i];
                for(char ch = 'a'; ch <= 'z'; ch ++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = originalChar;
            }
        }
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};


int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution sol;
    vector<vector<string>>  res = sol.findLadders(beginWord, endWord, wordList);
    
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