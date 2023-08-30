#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
      int ans=0;
      void fun(int cnt,int n,int vis[]) {
           if(cnt==n) {
               ans++;
               return;
           }
           for(int i=1;i<=n;i++) {
               if(vis[i]==0 and ((cnt+1)%i==0 or i%(cnt+1)==0)) {
                    vis[i]=1;
                    fun(cnt+1,n,vis);
                    vis[i]=0;
               }
           }
      }
    int countArrangement(int n) {
         int vis[16]={0};
         fun(0,n,vis);
         return ans;
    }
};