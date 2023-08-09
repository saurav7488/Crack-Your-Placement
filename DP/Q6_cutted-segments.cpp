#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int fun(int n,int x,int y,int z,vector<int>&dp) {
         if(n==0) return 0;
         if(dp[n]!=-1) return dp[n];
         int ans=INT_MIN;
         if(n>=x) ans=max(ans,1+fun(n-x,x,y,z,dp));
         if(n>=y) ans=max(ans,1+fun(n-y,x,y,z,dp));
         if(n>=z) ans=max(ans,1+fun(n-z,x,y,z,dp));
         
         return  dp[n]=ans;
         
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        // int ans=fun(n,x,y,z,dp);
        // return ans>=0?ans:0;
        dp[0]=0;
        for(int i=1;i<=n;i++) {
             if(i>=x and dp[i-x]!=-1) dp[i]=max(dp[i],1+dp[i-x]);
             if(i>=y and dp[i-y]!=-1) dp[i]=max(dp[i],1+dp[i-y]);
             if(i>=z and dp[i-z]!=-1) dp[i]=max(dp[i],1+dp[i-z]);
            //  dp[i]=ans;
        }
        return dp[n]>=0?dp[n]:0;
    }
};
