#include<bits/stdc++.h>
using namespace std;
void printDuplicates(string& t) {
      vector<int>cnt(26,0);
      int n=t.size();
      for(int i=0;i<n;i++) {
          cnt[t[i]-'a']++;
      }
      for(int i=0;i<26;i++) {
          if(cnt[i]>1) {
               cout<<char(i+'a')<<" "<<cnt[i]<<"\n";
          }
      }
} 
int main() {
     string t="geeksforgeeks";
     printDuplicates(t);
}

// tc O(N)
// sc O(26)