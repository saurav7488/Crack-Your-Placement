#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.size();
        string simplify="";
        for(int i=0;i<n;i++) {
              if(path[i]=='/') continue;
              string temp="";
              while(i<n and path[i]!='/') temp+=path[i++];
              if(temp==".") continue;
              else if(temp=="..") {
                   if(!st.empty()) st.pop();
              }
              else{
                  st.push(temp);
              }
        }
        if(st.size()==0) simplify+="/";
        while(!st.empty()) {
             simplify="/"+st.top()+simplify;
             st.pop();
        }
        return simplify;
    }
};

// TC->O(N)
// SC->O(N)












