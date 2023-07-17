#include<bits/stdc++.h>
using namespace std;
// using recursion 
// Give TLE


class Solution {
public:
    int fun(int i,vector<int>&prices,int buy) {
         if(i==prices.size()) return 0;
         if(buy==1) {
              int op1=-prices[i]+fun(i+1,prices,0);
              int op2=fun(i+1,prices,1);
              return max(op1,op2);
         }
         return max(prices[i]+fun(i+1,prices,1),fun(i+1,prices,0));
    }
    int maxProfit(vector<int>& prices) {
        return fun(0,prices,1);
    }
};

// memoization

class Solution {
public:
    int fun(int i,vector<int>&prices,int buy,vector<vector<int>>&dp) {
         if(i==prices.size()) return 0;
         if(dp[i][buy]!=-1) return dp[i][buy];
         if(buy==1) {
              int op1=-prices[i]+fun(i+1,prices,0,dp);
              int op2=fun(i+1,prices,1,dp);
              return dp[i][buy]=max(op1,op2);
         }
         return dp[i][buy]=max(prices[i]+fun(i+1,prices,1,dp),fun(i+1,prices,0,dp));
    }
    int maxProfit(vector<int>& prices) {
       vector<vector<int>>dp(prices.size(),vector<int>(3,-1));
        return fun(0,prices,1,dp);
    }
};


//Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<vector<int>>dp(prices.size()+1,vector<int>(3,0));
        for(int i=prices.size()-1;i>=0;i--) {
            for(int buy=1;buy>=0;buy--) {
                 if(buy==1) {
                      int op1=-prices[i]+dp[i+1][0];
                      int op2=dp[i+1][1];
                      dp[i][buy]=max(op1,op2);
                 }
                 else
                 dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};













