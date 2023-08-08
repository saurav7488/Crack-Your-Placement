#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // TC->O(N)
  // SC->O(1)
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++) {
            if(nums[i]<0) swap(mini,maxi);
            maxi=max(maxi*nums[i],nums[i]);
            mini=min(mini*nums[i],nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};