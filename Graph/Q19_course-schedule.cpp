#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int i,vector<vector<int>>&g,vector<bool>&vis,vector<bool>&revdfs) {
          vis[i]=true;
          revdfs[i]=true;
          for(auto it:g[i]) {
               if(!vis[it]) {
                    if(dfs(it,g,vis,revdfs)) return true;
               }
               else{
                    if(revdfs[it]) return true;
               }
          }
          revdfs[i]=false;
          return false;
    }
    bool canFinish(int n, vector<vector<int>>&adj) {
          vector<vector<int>>g(n+1);
          for(int i=0;i<adj.size();i++) {
               g[adj[i][0]].push_back(adj[i][1]);             
          }
          vector<bool>vis(n+1,false);
          vector<bool>revdfs(n+1,false);
          for(int i=0;i<n;i++) {
              
              if(!vis[i] and dfs(i,g,vis,revdfs)) return false;
          }
          return true;
    }
};
