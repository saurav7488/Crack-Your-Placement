#include<bits/stdc++.h>
using namespace std;
// Tc->O(V+E)
// Sc-> O(V)


// DFS



// class Solution
// {
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	void fun(int i,stack<int>&st,vector<int>adj[],vector<bool>&vis) {
// 	      vis[i]=true;
// 	      for(auto it:adj[i]) {
// 	            if(vis[it]) continue;
// 	            fun(it,st,adj,vis);
// 	      }
// 	      st.push(i);
// 	}
// 	vector<int> topoSort(int n, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    stack<int>st;
// 	    vector<bool>vis(n,false);
// 	    for(int i=0;i<n;i++) {
// 	         if(!vis[i]) {
// 	               fun(i,st,adj,vis);
// 	         }
// 	    }
// 	    vector<int>ans;
// 	    while(!st.empty()) {
// 	         ans.push_back(st.top());
// 	         st.pop();
// 	    }
// 	    return ans;
// 	}
// };

// BFS

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{ 
	      vector<int>indegree(n+1,0);
	      vector<int>ans;
	      queue<int>q;
	      for(int i=0;i<n;i++) {
	           for(auto it:adj[i]) {
	                indegree[it]++;
	           }
	      }
	      for(int i=0;i<n;i++) {
	            if(indegree[i]==0) q.push(i);
	      }
	      while(!q.empty()) {
	            int sz=q.size();
	            while(sz--) {
	                 int curr=q.front();
	                 q.pop();
	                 ans.push_back(curr);
	                 for(auto it:adj[curr]) {
	                      if(--indegree[it]==0) q.push(it);
	                 }
	            }
	      }
	      return ans;
	}
};


