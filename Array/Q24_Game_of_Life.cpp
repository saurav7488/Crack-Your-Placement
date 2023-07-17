#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLive(int c) {
        return c==1;
    }
    int count(int i,int j,vector<vector<int>>board){
        int cnt=0;
        if(i-1>=0 and board[i-1][j]==1) cnt++;
        if(i+1<board.size() and board[i+1][j]==1) cnt++;
        if(j-1>=0 and board[i][j-1]==1) cnt++;
        if(j+1<board[0].size() and board[i][j+1]==1) cnt++;
        if(i-1>=0 and j-1>=0 and board[i-1][j-1]==1) cnt++;
        if(i+1<board.size() and j+1<board[0].size() and board[i+1][j+1]==1) cnt++;
        if(i-1>=0 and j+1<board[0].size() and board[i-1][j+1]==1) cnt++;
        if(i+1<board.size() and j-1>=0 and board[i+1][j-1]==1) cnt++;
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
         vector<vector<int>>board1=board;
         int row=board.size();
         int col=board[0].size();
         for(int i=0;i<row;i++) {
             for(int j=0;j<col;j++) {
                  if(isLive(board[i][j])) {
                      int res=count(i,j,board1);   
                      if(res<2 or res>3) board[i][j]=0;
                  }
                  else{
                      int res=count(i,j,board1);   
                      if(res==3) board[i][j]=1;
                  }
             }
         }
    }
};