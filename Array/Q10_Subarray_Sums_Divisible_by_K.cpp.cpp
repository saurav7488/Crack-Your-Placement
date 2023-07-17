#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,cnt=0;
        map<int,int>m;
        m[0]++;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            int res=sum%k;
            if(res<0) res+=k;
            if(m[res]) cnt+=m[res];
            m[res]++;
        }
        return cnt;
    }
};