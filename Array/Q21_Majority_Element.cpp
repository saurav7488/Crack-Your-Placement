#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int arr=0;
        for(int i=0;i<nums.size();i++) {
            if(cnt==0) {
                arr=nums[i];
                cnt++;
            }
            else if(arr!=nums[i]) cnt--;
            else{
                 cnt++;
            }
        }
        return arr;
    }
};