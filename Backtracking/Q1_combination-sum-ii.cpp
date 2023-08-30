#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fun(int idx,vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int tar) {
          if(tar==0) {
              ans.push_back(temp);
              return;
          }
          for(int i=idx;i<nums.size();i++) {
              if(i>idx and nums[i-1]==nums[i]) continue;
              if(nums[i]>tar) continue;
              temp.push_back(nums[i]);
              fun(i+1,ans,temp,nums,tar-nums[i]);
              temp.pop_back();
          }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        fun(0,ans,temp,candidates,target);
        return ans;
    }
};