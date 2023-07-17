#include<bits/stdc++.h>
using namespace std;
void combination(vector<int>&arr,int r,int i,int count,vector<int>&cur,vector<vector<int>>&ans) {
      if(count==r) {
          ans.push_back(cur);
          return;
      }
      cur.push_back(arr[i]);
      combination(arr,r,i+1,count+1,cur,ans);
      while(arr[i]==arr[i+1]) i++;
      cur.pop_back();
      combination(arr,r,i+1,count,cur,ans);
}
int main(){
      int r=3;
      vector<int>arr={5,4,3,2,1};
      sort(arr.begin(),arr.end());
      vector<int>cur;
      vector<vector<int>> ans;
      combination(arr,r,0,0,cur,ans);
      for(int i=0;i<ans.size();i++) {
         for(int j=0;j<ans[i].size();j++) {
              cout<<ans[i][j]<<" ";
         }
         cout<<"\n";
      }
}