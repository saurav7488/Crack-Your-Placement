#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // TC-> O(N)
  // SC-> O(N)+O(N)
    int fun(int i,vector<int>&dp) {
        if(i<0) return 0;
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int a=fun(i-1,dp);
        int b=fun(i-2,dp);
        return dp[i]=a+b;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // return fun(n,dp);

        // TC->O(N)
        // SC->O(N)
        dp[0]=1;
        dp[1]=1; 
        for(int i=2;i<=n;i++) {
             int a=dp[i-1];
             int b=dp[i-2];
             dp[i]=a+b;
        }
        for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
        return dp[n];
    }
};