#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int tree( vector<vector<int>>adj[],int n) {
	      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	      vector<int>vis(n,0);
	      int sum=0;
	      q.push({0,0});
	      while(!q.empty()) {
	            auto it=q.top();
	            int wt=it.first;
	            int node=it.second;
	            q.pop();
	            if(vis[node]) continue;
	            vis[node]=1;
	            sum+=wt;
	            for(auto i:adj[node]) {
	                  int n1=i[0];
	                  int w=i[1];
	                  if(vis[n1]) continue;
	                  q.push({w,n1});
	            }
	      }
	      return sum;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        return tree(adj,V);
    }
};

// TC -> Elog(V)
// Sc -> O(V)