#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int store=0;
        for(int i=0;i<n;i++) {
             if(s[i]!=' ') {
                 if(store!=0) s[store++]=' ';
                 int j=i;
                 while(j<n and s[j]!=' ') s[store++]=s[j++];
                 reverse(s.begin()+store-(j-i),s.begin()+store);
                 i=j;
             }
        }
        s.erase(s.begin()+store,s.end());
        return s;
    }
};

// Tc->O(N)
// SC->O(1)







