#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],vector<int>&ans,int i,vector<bool>&vis) {
         vis[i]=true;
         ans.push_back(i);
         for(auto it:adj[i]) {
               if(vis[it]) continue;
               dfs(adj,ans,it,vis);
         }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>vis(V+1,false);
        dfs(adj,ans,0,vis);
        return ans;
    }
};

