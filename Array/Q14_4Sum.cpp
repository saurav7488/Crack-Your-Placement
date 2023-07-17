#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n=nums.size();
         vector<vector<int>>ans;
         if(n<4) return ans;
         sort(nums.begin(),nums.end());
         for(int i=0;i<n;i++) {
             for(int j=i+1;j<n;j++) {
                 long long int new_target=(long long)target-(long long)nums[i]-(long long)nums[j];
                 int a=j+1,b=n-1;
                 while(a<b) {
                     int num=nums[a]+nums[b];
                     if(num==new_target) {
                         ans.push_back({nums[i],nums[j],nums[a],nums[b]});
                         int val=nums[a];
                         while(a<n and val==nums[a]) a++;
                         val=nums[b];
                         while(b>=0 and nums[b]==val) b--;
                     }
                     else if(num>new_target) b--;
                     else a++; 
                 }
                 while(j+1<n and nums[j]==nums[j+1]) j++;
             }
             while(i+1<n and nums[i]==nums[i+1]) i++;
         }
         return ans;
    }
};

// Tc->O(n^3)
// sc->O(1)