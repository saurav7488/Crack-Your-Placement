#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int fun(int i,int sum,int arr[],int tar,vector<vector<int>>&dp) {
          if(i<0 and sum!=tar) return 0;
          if(sum==tar) return 1;
          if(sum<tar) return 0;
          if(dp[i][sum]!=-1) return dp[i][sum];
          return dp[i][sum]=fun(i-1,sum,arr,tar,dp) or fun(i-1,sum-arr[i],arr,tar,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        int tar=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return fun(N-1,sum,arr,tar,dp);
    }
};



