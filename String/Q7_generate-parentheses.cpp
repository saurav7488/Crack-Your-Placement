#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int open , int close,string s,vector<string>&ans) {
        if(open==0 and close==0) {
            ans.push_back(s);
            return;
        }
         if(open==close) {
              string op1=s;
              op1.push_back('(');
              fun(open-1,close,op1,ans);
         }
         else if(open==0) {
              string op1=s;
              op1.push_back(')');
              fun(open,close-1,op1,ans);
         }
         else if(close==0) {
             string op1=s;
              op1.push_back('(');
             fun(open-1,close,op1,ans);
         }
         else{
             string op1=s;
             string op2=s;
              op1.push_back('(');
              op2.push_back(')');
             fun(open-1,close,op1,ans);
             fun(open,close-1,op2,ans);
         }
    }
    vector<string> generateParenthesis(int n) {
         int open=n;
         int close=n;
         vector<string>ans;
         string s="";
         fun(close,open,s,ans);
         return ans;
    }
};



// TC-> O(2^n)
// SC->O(N)