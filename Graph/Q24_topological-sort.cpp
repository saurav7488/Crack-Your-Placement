#include<bits/stdc++.h>
using namespace std;
// Tc->O(V+E)
// Sc-> O(N)+O(n)+O(N)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void fun(int i,stack<int>&st,vector<int>adj[],vector<bool>&vis) {
	      vis[i]=true;
	      for(auto it:adj[i]) {
	            if(vis[it]) continue;
	            fun(it,st,adj,vis);
	      }
	      st.push(i);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<bool>vis(n,false);
	    for(int i=0;i<n;i++) {
	         if(!vis[i]) {
	               fun(i,st,adj,vis);
	         }
	    }
	    vector<int>ans;
	    while(!st.empty()) {
	         ans.push_back(st.top());
	         st.pop();
	    }
	    return ans;
	}
};
