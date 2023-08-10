#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // TC->O(NxN)
  // SC->O(NxN)+O(N)
    int dp[101][101];
    int fun(int i,string& s,int num) {
       if(num<1 and num>26) return 0;
        if(i<0) return 1;  
        if(dp[i][num+1]!=-1) return dp[i][num+1];
        int mov1=0,mov2=0;
        num=s[i]-'0';
        if(num!=0) mov1=fun(i-1,s,num);
        if(i>0) {
            num=0;
            num=(s[i-1]-'0')*10;
            if(num!=0) num=num+s[i]-'0';
            if(num>=1 and num<=26)
            mov2=fun(i-2,s,num);
        }
        return  dp[i][num+1]=mov1+mov2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0') return 0;
        return fun(s.size()-1,s,-1);
    }
};