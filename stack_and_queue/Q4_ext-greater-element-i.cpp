#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
         map<int,int>m;
         vector<int>ans;
         stack<int>st;
         for(int i=n2.size()-1;i>=0;i--) {
              while(!st.empty() and st.top()<=n2[i]) st.pop();
              if(!st.empty() and st.top()>n2[i]) {
                  m[n2[i]]=st.top();
              }
              else{
                  m[n2[i]]=-1;
              }
              st.push(n2[i]);
         }
         for(auto it:n1) ans.push_back(m[it]);
         return ans;
    }
};