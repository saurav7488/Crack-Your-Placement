#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs( vector<int> adj[],vector<bool>&vis,vector<bool>&revdfs,int i) {
           vis[i]=true;
           revdfs[i]=true;
           for(auto it:adj[i]) {
                if(!vis[it]) {
                      if(dfs(adj,vis,revdfs,it)) return true;
                }
                else{
                     if(revdfs[it]) return true;
                }
           }
           revdfs[i]=false;
           return false;
           
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false),revdfs(V,false);
        for(int i=0;i<V;i++) {
             if(!vis[i]) {
                   if(dfs(adj,vis,revdfs,i)) return true;
             } 
        }
        return false;
    }
};
