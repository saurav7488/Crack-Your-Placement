#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cur=nums[0];
        if(n==1) return true;
        for(int i=0;i<n;i++) {
            if(cur==0) return false;
            cur--;
            cur=max(cur,nums[i]);
        }
        return true;
    }
};