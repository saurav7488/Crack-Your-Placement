#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool fun( vector<int> adj[],vector<bool>&vis,int i,int par) {
          vis[i]=true;
          for(auto it:adj[i]) {
               if(vis[it] and it!=par) return true;
               if(vis[it]) continue;
               if(fun(adj,vis,it,i)) return true;
               
          }
          return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++) {
             if(!vis[i]) {
                   bool res=fun(adj,vis,i,-1);
                   if(res) return true;
             }
        }
        return false;
    }
};