#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(int i,int end,vector<vector<int>>&nums,vector<int>&dp) {
         if(i>=nums.size()) return 0;
         if(nums[i][0]<end) {
               return fun(i+1,end,nums,dp);
         }
          if(dp[i]!=-1) return dp[i];
         return  dp[i]= max(fun(i+1,end,nums,dp),nums[i][2]+fun(i+1,nums[i][1],nums,dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>v;
        int n=startTime.size();
        for(int i=0;i<n;i++) {
             v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int>dp(n+1,-1);
        return fun(0,0,v,dp);
    }
};