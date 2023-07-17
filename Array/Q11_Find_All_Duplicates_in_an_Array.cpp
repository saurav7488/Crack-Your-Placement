#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int>ans;
       for(int i=0;i<nums.size();i++) {
            int in=abs(nums[i]);
            if(nums[in-1]>0) nums[in-1]*=-1;
            else ans.push_back(abs(nums[i]));
       }
        return ans;
    }
};