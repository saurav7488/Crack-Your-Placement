#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int i,int j,int n, vector<vector<bool>>&vis) {
         if(i>=0 and j>=0 and i<n and j<n and vis[i][j]==false) return true;
         return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n=N;
	    int x=KnightPos[0]-1,y=KnightPos[1]-1;
	    int tx=TargetPos[0]-1,ty=TargetPos[1]-1;
	    if(x==tx and y==ty) return 0;
	    vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
	    queue<pair<int,int>>q;
	    q.push({x,y});
	    vis[x][y]=true;
	    int step=0;
	    while(!q.empty()) {
	          int sz=q.size();
	          int a[8]={1,-1,-2,2,-2,-1,1,2};
	          int b[8]={2,2,1,1,-1,-2,-2,-1};
	          while(sz--) {
	               pair<int,int>p=q.front();
	               q.pop();
	               int ax=p.first;
	               int ay=p.second;
	               if(ax==tx and ay==ty) return step;
	               for(int i=0;i<8;i++) {
	                     int nx=ax+a[i];
	                     int ny=ay+b[i];
	                     if(isValid(nx,ny,n,vis)) {
	                           vis[nx][ny]=true;
	                           q.push({nx,ny});
	                     }
	               }
	          }
	          step++;
	    }
	    return step;
	}
};