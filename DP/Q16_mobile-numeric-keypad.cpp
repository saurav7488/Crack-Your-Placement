#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
	long long dp[5][4][26];
	long long fun(int i,int j,int n,vector<vector<int>>&adj) {
	      if(i<0 or j<0 or i>=4 or j>=3 or adj[i][j]==-1) return 0;
	      if(n==1) return 1;
	      if(dp[i][j][n]!=-1) return dp[i][j][n];
	      long long  up=fun(i-1,j,n-1,adj);
	      long long left=fun(i,j-1,n-1,adj);
	      long long right=fun(i,j+1,n-1,adj);
	      long long down=fun(i+1,j,n-1,adj);
	      long long same=fun(i,j,n-1,adj);
	      return  dp[i][j][n]=up+left+down+right+same;
	}
	long long getCount(int n)
	{   memset(dp,-1,sizeof(dp));
		vector<vector<int>>adj={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
		long long ans=0;
		for(int i=0;i<4;i++) {
		     for(int j=0;j<3;j++) {
		          if(adj[i][j]!=-1) {
		                ans+=fun(i,j,n,adj);
		          }
		     }
		}
		return ans;
	}


};