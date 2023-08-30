#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans; 
    set<vector<int>>s;
    void helper(int indx,vector<int>&nums){
          if(indx==nums.size()){
               s.insert(nums);
          }
        for(int i=indx;i<nums.size();i++){ 
            swap(nums[indx],nums[i]);
            helper(indx+1,nums);
            swap(nums[indx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0,nums);
        for(auto &a:s) ans.push_back(a);
        return ans;
    }
};














