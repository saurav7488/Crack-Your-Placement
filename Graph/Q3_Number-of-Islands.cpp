#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid) {
          if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0') return;
          grid[i][j]='0';
          dfs(i+1,j,grid);
          dfs(i-1,j,grid);
          dfs(i,j+1,grid);
          dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
         int cnt_island=0;
         int row=grid.size();
         int col=grid[0].size();
         for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]=='1') {
                     dfs(i,j,grid);
                     cnt_island++;
                }
            }
         }
         return cnt_island;
    }
};