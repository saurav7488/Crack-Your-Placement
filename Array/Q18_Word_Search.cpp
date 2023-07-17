#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool fun(int i,int j,vector<vector<char>>&board,string& word,int idx) {
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or word[idx]!=board[i][j]) return false;
        if(idx==word.size()-1) return true;
        board[i][j]='#';
        if(fun(i+1,j,board,word,idx+1) or fun(i-1,j,board,word,idx+1) or fun(i,j+1,board,word,idx+1)
         or fun(i,j-1,board,word,idx+1) ) return true;
         board[i][j]=word[idx];
         return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(fun(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};

