#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<pair<int,int>>>g(n);
         for(auto it:edges) {
             g[it[0]].push_back({it[1],it[2]});
             g[it[1]].push_back({it[0],it[2]});
         }
         int city=-1,ans=1e8;
         for(int i=0;i<n;i++) {
             queue<pair<int,int>>q;
             vector<int>dist(n,1e8);
             dist[i]=0;
             q.push({i,0});
             while(!q.empty()) {
                 int node=q.front().first;
                 int w=q.front().second;
                 q.pop();
                 for(auto it:g[node]) {
                     int n1=it.first;
                     int w1=it.second;
                     if((w1+w)<dist[n1]) {
                          q.push({n1,w+w1});
                          dist[n1]=w+w1;
                     }
                 }
             }
             int cnt=0;
             for(int j=0;j<n;j++) {
                  if(dist[j]<=distanceThreshold) cnt++;
             }
             if(cnt<=ans) {
                 ans=cnt;
                 city=max(city,i);
             }
         }
         return city;
    }
};