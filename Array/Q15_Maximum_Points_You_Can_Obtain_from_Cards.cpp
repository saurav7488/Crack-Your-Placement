#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(auto i:cardPoints) sum+=i;
        int win=0,ans=0;
        if(n==k) return sum;
        for(int i=0;i<n-k-1;i++) win+=cardPoints[i];
        for(int i=n-k-1;i<n;i++) {
            win+=cardPoints[i];
            ans=max(ans,sum-win);
            win-=cardPoints[i-(n-k-1)];
        }
        return ans;
    }
};