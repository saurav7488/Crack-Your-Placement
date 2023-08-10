#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // TC->O(nxn)
    // sc->O(nxn)+O(n)
    // int dp[2600][2600];
    // int fun(int i,vector<int>&nums,int num) {
    //       if(i<0) return 0;   
    //       if(dp[i][num+1]!=-1) return dp[i][num+1];
    //       int take=0,not_take=0;
    //       if(num==-1 or nums[i]<nums[num]) take=1+fun(i-1,nums,i);
    //       not_take=0+fun(i-1,nums,num);
    //       return  dp[i][num+1]=max(take,not_take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int n=nums.size();
        // return fun(n-1,nums,-1);
        if(n==1) return 1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

       for(int i=n-1;i>=0;i--) {
           for(int j=i-1;j>=-1;j--) {
               int op=dp[i+1][j+1];
               if(j==-1 or nums[i]>nums[j]) op=max(op,1+dp[i+1][i+1]);
               dp[i][j+1]=op;
           }
       }
       return dp[0][0];
    }
};


