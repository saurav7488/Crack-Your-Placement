#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    vector<int> dist(V , 1e8);
        
        dist[0] = 0;
        
        for(int i = 0 ; i < V-1 ; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
             for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] + wt < dist[v]){
                   return 1;
                }
            }
            
           return 0;
	}
};

// TC-> O(N-1)*O(E)
// sc-> O(N)
