#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   // nums[i]+nums[j]==target
    vector<int> twoSum(vector<int>& nums, int target) {
         int a=0,b=0,n=nums.size();
         map<int,int>m;
         for(int i=0;i<n;i++) {
             if(m.find(target-nums[i])!=m.end()) {
                  a=m[target-nums[i]];
                  b=i;
                  break;
             }
             m[nums[i]]={i};
         }
         return {a,b};
    }
};