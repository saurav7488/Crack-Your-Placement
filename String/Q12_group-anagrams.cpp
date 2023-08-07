#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string,vector<string>>m;
         vector<vector<string>>ans;
         for(int i=0;i<strs.size();i++) {
             string curr=strs[i];
             string tmp(26,0);
             for(auto it:strs[i]) {
                 tmp[it-'a']++;
             }
             m[tmp].push_back(curr);
         }
         for(auto it:m) {
             vector<string>tmp;
             for(auto i:it.second) tmp.push_back(i);
             ans.push_back(tmp);
         }
         return ans;
    }
};

// TC->O(N)
// TC->O(N)