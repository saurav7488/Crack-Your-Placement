#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string s, string t) {
         int n=s.size();
         int m=t.size();
         if(m>n) return -1;
         int i=0;
         while(i<n) {
              if(s[i]==t[0]) {
                  int j=0;
                  int ind=i;
                  int ans=i;
                  while(ind<n and j<m and s[ind]==t[j]) {
                      ind++,j++;
                  }
                  if(j==m) return ans;
              }
              i++;
         }
         return -1;
    }
};

// tc-> O(n+m)
// sc-> O(1)