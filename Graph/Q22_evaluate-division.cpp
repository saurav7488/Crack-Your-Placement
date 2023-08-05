#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// TC->O(e*n)
// sc->O(v)
void dfs (string s,string d,map<string,vector<pair<string,double>>>&m,set<string>&vis,double& ans,double temp) {
     if(vis.find(s)!=vis.end()) {
         return;
     }
     else{
          vis.insert(s);
          if(s==d) {
              ans=temp;
              return;
          }
          else{
               for(auto it:m[s]) {
                  //  int temp1=temp;
                  //  temp=temp*it.second;
                   dfs(it.first,d,m,vis,ans,temp*it.second);
                  //  temp=temp1;
               }
          }
     }
}
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>&q) {
         map<string,vector<pair<string,double>>>m;
         for(int i=0;i<e.size();i++) {
               m[e[i][0]].push_back({e[i][1],v[i]});
               m[e[i][1]].push_back({e[i][0],1/v[i]});
         }
         vector<double>res;
         for(int i=0;i<q.size();i++) {
              string s=q[i][0];
              string d=q[i][1];
              set<string>vis;
              double ans=-1.0;
              if(m.find(s)!=m.end())
              dfs(s,d,m,vis,ans,1.0);
              res.push_back(ans);
         }
         return res;
    }
};







