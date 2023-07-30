#include<bits/stdc++.h>
using namespace std;
class Solution
{   // 1.Topological sort
    // 2.Transpose graph
    // 3. DFS
	public:
	//Function to find number of strongly connected components in the graph.
	void topo(vector<vector<int>>&adj,int i,vector<bool>&vis,stack<int>&st) {  
	      vis[i]=true;
	      for(auto it:adj[i]) {
	            if(vis[it]) continue;
	            topo(adj,it,vis,st);
	      }
	      st.push(i);
	}
	void dfs(vector<bool>&vis,vector<vector<int>>&g,int i) {
	      vis[i]=true;
	      for(auto it:g[i]) {
	            if(vis[it]) continue;
	            dfs(vis,g,it);
	      }
	}

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool>vis(V,false);
        stack<int>st;
        for(int i=0;i<V;i++) {
              if(!vis[i]) {
                   topo(adj,i,vis,st);
              }
        }
        
        // Transpose
        vector<vector<int>>g(V+1);
        for(int i=0;i<V;i++) {
              vis[i]=false;
              for(int j=0;j<adj[i].size();j++) {
                    g[adj[i][j]].push_back(i);
              }
        }
        
        int ans=0;
        
        while(!st.empty()) {
               int num=st.top();
               st.pop();
               if(!vis[num]) {
                     ans++;
                     dfs(vis,g,num);
               }
        }
        
        return ans;
        
        
    }
};