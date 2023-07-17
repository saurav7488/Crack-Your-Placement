#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high) {
         int cnt=0;
         int j=mid+1;
         for(int i=low;i<=mid;i++) {
             while(j<=high and nums[i]>nums[j]*2LL) j++;
             cnt+=(j-(mid+1));
         }
         int left=low,right=mid+1;
         vector<int>temp;
         while(left<=mid and right<=high) {
             if(nums[left]<nums[right]) {
                 temp.push_back(nums[left]);
                 left++;
             }
             else{
                 temp.push_back(nums[right]);
                 right++;
             }
         }
         while(left<=mid) temp.push_back(nums[left++]);
         while(right<=high) temp.push_back(nums[right++]);
         for(int i=low;i<=high;i++) {
              nums[i]=temp[i-low];
         }
         return cnt;
    }
    
    int mergeSort(vector<int>&nums,int i,int j) {
        int cnt=0;
        if(i==j) return cnt;
        int mid=(i+j)/2;
        cnt+=mergeSort(nums,i,mid);
        cnt+=mergeSort(nums,mid+1,j);
        cnt+=merge(nums,i,mid,j);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};