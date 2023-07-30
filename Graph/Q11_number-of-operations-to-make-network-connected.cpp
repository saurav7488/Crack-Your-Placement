#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,vector<vector<int>>&g,vector<bool>&vis) {
         vis[i]=true;
         for(auto it:g[i]) {
             if(vis[it]) continue;
             dfs(it,g,vis);
         } 
    }
    int makeConnected(int n, vector<vector<int>>& connection) {
        vector<bool>vis(n+1,false);
        int cnt=0;
        if(connection.size()<n-1) return -1;
        vector<vector<int>>g(n+1);
        for(int i=0;i<connection.size();i++) {
             g[connection[i][0]].push_back(connection[i][1]);
             g[connection[i][1]].push_back(connection[i][0]);
        }
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                 dfs(i,g,vis);
                 cnt++;
            }
        }
        return cnt-1;
    }
};