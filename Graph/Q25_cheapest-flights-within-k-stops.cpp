#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>g(n);
        for(auto flight : flights){
            g[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int>dist(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto num = q.front();
                int curr=num.first;
                int wt=num.second;
                q.pop();
                for (auto it : g[curr]) {
                    if (it.second + wt < dist[it.first]){
                        dist[it.first] = it.second + wt;
                        q.push({it.first, dist[it.first]});
                    }
                }
            }
            stops++;
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};


// Tc->O(k*E)
// sc->(V)