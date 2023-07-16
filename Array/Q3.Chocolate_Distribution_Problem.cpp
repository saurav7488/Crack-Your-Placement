#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
            sort(a.begin(),a.end());
            int i=0,j=m-1,cnt=INT_MAX;
            while(j<n) {
                 int res=abs(a[i]-a[j]);
                 cnt=min(cnt,res);
                 i++,j++;
            }
            return cnt;
    }   
};
