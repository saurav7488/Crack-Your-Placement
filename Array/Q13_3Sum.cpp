#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++) {
            if(i>0 and nums[i]==nums[i-1]) continue;
            int a=i+1,b=n-1;
            while(a<b) {
                int new_target=nums[i]+nums[a]+nums[b];
                if(new_target==0) {
                     ans.push_back({nums[i],nums[a],nums[b]});
                     int val=nums[a];
                     while(a<n and val==nums[a]) a++;
                     val=nums[b];
                     while(b>=0 and val==nums[b]) b--;
                }
                else if(new_target>0) b--;
                else a++;
            }
        }
        return ans;
    }
};

