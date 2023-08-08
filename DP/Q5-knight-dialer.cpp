#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // TC - O(3x4)+O(N)
  // SC - O(N) + O(N)
    long long int mod=1e9+7;
    int a[8]={2,2,1,1,-2,-2,-1,-1};
    int b[8]={1,-1,2,-2,1,-1,2,-2};
    int dp[5][4][5002];
    int fun(int i,int j,vector<vector<int>>&adj,int n) {
        if(i<0 or j<0 or i>=adj.size() or j>=adj[0].size() or adj[i][j]==-1) return 0;
        if(n==0) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        int ans=0;
        for(int k=0;k<8;k++) {
            int x=a[k]+i;
            int y=b[k]+j;
            ans=(ans+fun(x,y,adj,n-1))%mod;
        }
        return  dp[i][j][n]= ans%mod;
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>adj(4,vector<int>(3,-1));
        int x=1;
        adj[3][1]=0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                 adj[i][j]=x;
                 x++;
            }
        }
       int ans=0;
       for(int i=0;i<4;i++) {
           for(int j=0;j<3;j++) {
               if(adj[i][j]!=-1) {
                   ans=(ans+fun(i,j,adj,n-1))%mod;
               }
           }
       }
       return ans%mod;
    }
};