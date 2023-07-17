    #include<bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n=nums.size();
            int cnt=0,sum=0;
            map<int,int>m;
            for(auto it:nums) {
                sum+=it;
                if(sum==k) cnt++;
                cnt+=m[sum-k];
                m[sum]++;
            }
            return cnt;
        }
    };