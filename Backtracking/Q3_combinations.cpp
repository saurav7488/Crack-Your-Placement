#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fun(int idx,vector<vector<int>>&ans,vector<int>&temp,int n,int k) {
         if(temp.size()==k) {
              ans.push_back(temp);
              return;
         }
         for(int i=idx;i<=n;i++) {
             temp.push_back(i);
             fun(i+1,ans,temp,n,k);
             temp.pop_back();
         }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(1,ans,temp,n,k);
        return ans;
    }
};