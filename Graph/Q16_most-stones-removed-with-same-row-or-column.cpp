#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int dfs(int idx,vector<vector<int>>& stones,vector<bool>&vis) {
        vis[idx]=true;
        int ans=0;
        for(int i=0;i<stones.size();i++) {
            if(!vis[i] and (stones[i][0]==stones[idx][0] or stones[i][1]==stones[idx][1])) 
            ans+=1+dfs(i,stones,vis);
        }
        return ans;
   }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);
        int res=0;
        for(int i=0;i<n;i++) {
             res+=dfs(i,stones,vis);
        }
        return res;
    }
};