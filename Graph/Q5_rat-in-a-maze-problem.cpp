#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void fun(vector<vector<int>>m,vector<string>&path,int i,int j,string c) {
           if(i==m.size()-1 and j==m.size()-1 and m[i][j]==1) {
                 path.push_back(c);
                 return;
           }
           if(i<0 or j<0 or i>=m.size() or j>=m[0].size() or m[i][j]==0) return;
           m[i][j]=0;
           fun(m,path,i+1,j,c+'D');
           fun(m,path,i-1,j,c+'U');
           fun(m,path,i,j+1,c+'R');
           fun(m,path,i,j-1,c+'L');
           
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) return {"-1"};
        vector<string> path;
        string c;
        fun(m,path,0,0,c);
        if(path.size()==0) return {"-1"};
        return path;
    }
};