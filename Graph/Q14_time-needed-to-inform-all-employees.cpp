#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<int>>m;
    int ans=0,mx=0;
    void dfs(int manager,vector<int>&time) {
         mx=max(mx,ans);
         for(auto employee:m[manager]) {
             ans+=time[manager];
             dfs(employee,time);
             ans-=time[manager];
         }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
          for(int i=0;i<n;i++) {
              if(manager[i]!=-1)
              m[manager[i]].push_back(i);
          }
          dfs(headID,informTime);
          return mx;
    }
};