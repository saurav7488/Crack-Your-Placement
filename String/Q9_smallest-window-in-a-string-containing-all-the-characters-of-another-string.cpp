#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
         int n=s.size();
         unordered_map<char,int>mt;
         int cnt=0;
         for(auto it:t) mt[it]++,cnt++;
         int l=0,r=0,len=INT_MAX;
         string ans="";
         while(r<n) {
              if(mt[s[r++]]-- > 0) cnt--; 
              if(cnt==0) {
                  while(mt[s[l]]<0) {
                       mt[s[l++]]++;
                  }
                  if(r-l<len) {
                       len=r-l; 
                       ans=s.substr(l,len);
                  } 
                  // cout<<s[l]<<"\n";
                   mt[s[l++]]++;
                   cnt++;
              }
         }
         return ans;
    }
};



// TC->O(N)
// SC->O(M)







