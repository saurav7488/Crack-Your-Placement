#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int rsize,int cosize,vector<int>&a,vector<int>&b){
    vis[r][c] = 1;
        for(int i=0;i<4;i++){
           int row = r + a[i];
           int  col = c + b[i];
            if(row >=0 && row<rsize && col>=0 && col<cosize && vis[row][col] == -1 && grid[row][col] == 1){
             
              dfs(row,col,grid,vis,rsize,cosize,a,b);
            }
     
}
}
int bfs2(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int rsize,int cosize,vector<int>&ri,vector<int>&ci,int identify){
    
    queue<pair<int,pair<int,int>>>qu;
    qu.push({r,{c,0}});
    while(!qu.empty()){
        int rows = qu.front().first,cols = qu.front().second.first,fliptime = qu.front().second.second;
        qu.pop();
        for(int i=0;i<4;i++){
           int row = rows + ri[i];
           int  col = cols + ci[i];
            if(row >=0 && row<rsize && col>=0 && col<cosize && vis[row][col] != identify && grid[row][col] == 0){
                vis[row][col] = identify;
                qu.push({row,{col,fliptime+1}});
            }else if(row >=0 && row<rsize && col>=0 && col<cosize && vis[row][col] == -1 && grid[row][col] == 1) return fliptime;
        }
    }
    return INT_MAX;
}
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        vector<int>a{1,-1,0,0};
        vector<int>b{0,0,-1,1};
        for(int i=0;i<m;i++){
            int f = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]) {
                    vis[i][j] = 1;
                dfs(i,j,grid,vis,m,n,a,b);
                f=1;
                break;
                }
            }
            if(f==1) break;
        }
        int mins = INT_MAX;
        int start = 3;
        for(int i=0;i<m;i++){
            for(int z=0;z<n;z++){
                if(vis[z][i] == 1){
                    vis[z][i] = 2;
                   int ans =  bfs2(z,i,grid,vis,m,n,a,b,start++);
                   mins = min(ans,mins);
                }
                
            }
            if(mins == 1) break;
        }
        return mins;
    }
};