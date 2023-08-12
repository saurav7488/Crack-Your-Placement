#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void sortColors(vector<int>& nums) {
     int n=nums.size();
     int l=0,m=0,h=n-1;
     while(m<=h) {
         if(nums[m]==0) {
             swap(nums[l++],nums[m++]);
         }
         else if(nums[m]==1) m++;
         else{
            swap(nums[m],nums[h--]);
         } 
     }
}
    // void sortColors(vector<int>& nums) {
    //     int n=nums.size();
    //     int i=0,j=n-1;
    //     while(i<j) {
    //         while(i<j and nums[j]!=0) j--;
    //         while(i<j and nums[i]==0) i++;
    //         swap(nums[i],nums[j]);
    //         i++,j--;
    //     }
    //     i=0,j=n-1;
    //     while(i<n and nums[i]==0) i++;
    //     while(i<j) {
    //        while(i<j and nums[j]!=1) j--;
    //        while(i<j and nums[i]==1) i++;
    //        swap(nums[i],nums[j]);
    //        i++,j--;
    //     }
    // }
};