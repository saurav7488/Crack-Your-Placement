#include<bits/stdc++.h>
using namespace std;
/*
 Tc-> (N)
 sc->O(N)   

*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++) {
             if(st.size()==0) st.push(s[i]);
             else if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
             else if(s[i]==')' or s[i]=='}' or s[i]==']') {
                  if(st.top()=='(' and s[i]==')') st.pop();
                  else  if(st.top()=='{' and s[i]=='}') st.pop();
                  else if(st.top()=='[' and s[i]==']') st.pop();
                  // else return false;
                  else st.push(s[i]);
             }
            
        }
        return st.size()==0;
    }
};







