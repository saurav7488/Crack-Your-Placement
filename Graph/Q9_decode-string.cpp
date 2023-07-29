#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
         int n=s.size();
         stack<char>st;
         string ans="";
         for(int i=0;i<n;i++) {
              if(s[i]==']') {
                // we run the while loop until not get openinig bracket
                  while(st.size()>0 and st.top()!='[') {
                      ans=st.top()+ans;
                      st.pop();
                  }
                  // At this point [ so , pop it
                  if(st.size()!=0) st.pop();
                  // pop digit and store it
                  string num="";
                  while(st.size()>0 and st.top()>='0' and st.top()<='9') {
                       num=st.top()+num;
                       st.pop();
                  }
                  // convert into it digit
                  int digit_n=stoi(num);
                  string tmp=ans;
                  for(int i=0;i<digit_n-1;i++) {
                      ans+=tmp;
                  }
                  // push all character of string ans in stack
                  for(int j=0;j<ans.size();j++) {
                       st.push(ans[j]);
                  }
                  // reset 
                  ans="";
              }
              else{
                  st.push(s[i]);
              }
         }
         while(st.size()>0) {
             ans=st.top()+ans;
             st.pop();
         }
         return ans;
    }
};



// TC->O(N^2)
// SC->O(N)