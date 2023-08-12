#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10005];
    int fun(int i,vector<int>&num) {
         if(i>=num.size()) return 0;
         if(dp[i]!=-1) return dp[i];
         int op1=num[i]+fun(i+2,num);
         int op2=0+fun(i+1,num);
         return  dp[i]=max(op1,op2);
    }
    int deleteAndEarn(vector<int>& nums) {
       memset(dp,-1,sizeof(dp));
        int n=nums.size();
        vector<int>num(10001,0);
        for(auto it:nums) num[it]+=it;
        return fun(0,num); 
    }
};