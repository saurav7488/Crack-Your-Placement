#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is(string&s,int i,int j) {
          while(i<=j) {
              if(s[i]!=s[j]) return false;
              i++,j--;
          }
          return true;
    }
    void fun(int idx,vector<vector<string>>&ans,vector<string>&temp,string&s) {
          if(idx==s.size()) {
               ans.push_back(temp);
               return;
          }
          for(int i=idx;i<s.size();i++) {
                if(is(s,idx,i)) {
                     temp.push_back(s.substr(idx,i+1-idx));
                     fun(i+1,ans,temp,s);
                     temp.pop_back();
                }
          }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        fun(0,ans,temp,s);
        return ans;
    }
};