#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>&g,vector<int>&vis,int i) {
         if(vis[i]==-1)
         vis[i]=1;
         for(auto it:g[i]) {
             if(vis[it]==-1) {
                 vis[it]=1-vis[i];
                 if(!dfs(g,vis,it)) return false;
             }
             else if(vis[it]==vis[i]) return false;
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++) {
            if(vis[i]==-1) {
                if(!dfs(graph,vis,i)) return false;
            }
        }
        return true;
    }
};