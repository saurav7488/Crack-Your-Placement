#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// TC-> O(Nxamount)
        // SC->O(nxamount) +O(n)
    int fun(int i,vector<int>&coins,int amount,vector<vector<int>>&dp) {
         if(amount<0) return 1e9;
         if(i<0) return 1e9;
         if(amount==0) return 0;
         if(dp[i][amount]!=-1) return dp[i][amount];
         int take=1+fun(i,coins,amount-coins[i],dp);
         int not_take=0+fun(i-1,coins,amount,dp);
         return  dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // int ans=fun(n-1,coins,amount,dp);
        // return ans==1e9?-1:ans;

        // TC-> O(Nxamount)
        // SC->O(nxamount) 
        for(int i=0;i<=n;i++) {
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++) dp[0][i]=1e9;
        for(int i=1;i<=n;i++) {
             for(int j=1;j<=amount;j++) {
                if(coins[i-1]>j) dp[i][j]=dp[i-1][j];
                 else dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
             }
        }

       return dp[n][amount]==1e9?-1:dp[n][amount];
    }
};





