#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool fun(vector<vector<int>>&g,int par,vector<int>vis,int i) {
         vis[i]=1;
         for(auto it:g[i]) {
               if(!vis[it]) {
                    if(fun(g,i,vis,it)) return true;
               }
               else if(par!=it) return true;
         }
         return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          vector<vector<int>>g(edges.size()+1);
          vector<int>vis(edges.size()+1,0);
          for(auto it:edges) {
               g[it[0]].push_back(it[1]);
               g[it[1]].push_back(it[0]);
               if(fun(g,-1,vis,it[0])) return {it};
          }
          return {};
    }
};



