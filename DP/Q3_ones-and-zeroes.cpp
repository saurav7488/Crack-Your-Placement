#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   // TC-> O(M x N )
   // sc -> O(M x N x I) +O(N)
    int dp[101][101][601];
    int fun(vector<pair<int,int>>&adj,int m,int n,int i) {  
        if(i==adj.size()) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int ans=0;
        if(m-adj[i].first>=0 and n-adj[i].second>=0) {
             ans=max(ans,1+fun(adj,m-adj[i].first,n-adj[i].second,i+1));
             ans=max(ans,fun(adj,m,n,i+1));
        }
        ans=max(ans,fun(adj,m,n,i+1));
        return dp[m][n][i]=ans;
    }
    pair<int,int> pairing(string s) {
        int x=0,y=0;
        for(auto it:s) {
            if(it=='0') x++;
            else y++;
        }
        return {x,y};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>adj;
        for(auto it:strs) {
            adj.push_back(pairing(it));
        }
        return fun(adj,m,n,0);
    }
};