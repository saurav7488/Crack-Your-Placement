#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n+1,vector<int>(m+1,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                     q.push({i,j});
                     dist[i][j]=0;
                }
            }
        }
        while(!q.empty()) {
              int sz=q.size();
              while(sz--) {
                  auto p=q.front();
                  int x=p.first;
                  int y=p.second;
                  q.pop();
                  int dx[4]={1,0,-1,0};
                  int dy[4]={0,1,0,-1};
                  for(int i=0;i<4;i++) {
                      int nx=dx[i]+x;
                      int ny=dy[i]+y;
                      int d=dist[x][y]+1;
                      if(nx>=0 and ny>=0 and nx<n and ny<m and d<dist[nx][ny]) {
                            dist[nx][ny]=d;
                            q.push({nx,ny});
                      }
                  }
              }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                 ans=max(ans,dist[i][j]);
            }
        }
         if(ans==0 or ans==INT_MAX) return -1;
        return ans;
    }
};
