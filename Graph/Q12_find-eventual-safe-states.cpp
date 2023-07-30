#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // bool dfs(vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&dfsvis,
    // vector<bool>&cycle_part,int i) {
    //       vis[i]=true;
    //       dfsvis[i]=true;
    //       for(auto it:graph[i]) {
    //           if(!vis[it]) {
    //                if(dfs(graph,vis,dfsvis,cycle_part,it))
    //                return cycle_part[i]=true;
    //           } 
    //           else{
    //               if(dfsvis[it]) return cycle_part[i]=true;
    //           }
    //       }
    //       dfsvis[i]=false;
    //       return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n=graph.size();
         vector<int>indegree(n+1,0);
         vector<vector<int>>g(n+1);
         for(int i=0;i<n;i++) {
             for(auto it:graph[i]) {
                  indegree[i]++;
                  g[it].push_back(i);
             }
         }
         queue<int>q;
         for(int i=0;i<n;i++) {
              if(indegree[i]==0) q.push(i);
         }
         vector<int>ans;
         while(!q.empty()) {
            int sz=q.size();
            while(sz--) {
                int num=q.front();
                q.pop();
                ans.push_back(num);
                for(auto it:g[num]) {
                    if(--indegree[it]==0) q.push(it);
                }
            }
         }
         sort(ans.begin(),ans.end());
         return ans;
        //  int n=graph.size();
        //  vector<vector<int>>g(n+1);
        //  vector<bool>vis(n+1,false),dfsvis(n+1,false),cycle_part(n+1,false);
        //  for(int i=0;i<n;i++) {
        //      if(!vis[i]) {
        //          dfs(graph,vis,dfsvis,cycle_part,i);
        //      }
        //  }
        //  vector<int>ans;
        //  for(int i=0;i<n;i++) {
        //      if(!cycle_part[i]) ans.push_back(i);
        //  }
        //  return ans;
    }
};