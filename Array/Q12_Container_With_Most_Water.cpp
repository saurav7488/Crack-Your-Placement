#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,area=0;
        while(left<right) {
             int res=(right-left)*min(height[left],height[right]);
             area=max(area,res);
             if(height[left]<height[right]) left++;
             else if(height[left]>height[right]) right--;
             else{ 
                 left++,right--;
             }
        }
        return area;
    }
};

// Tc->O(n)
// Sc->O(n)