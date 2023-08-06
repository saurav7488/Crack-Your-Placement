#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    bool is(int i,int j,string&s) {
         while(i<j) {
             if(s[i]==s[j]) i++,j--;
             else return false;
         }
         return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j) {
            if(s[i]==s[j]) {
                i++,j--;
            }
            else{
                return is(i+1,j,s) or is(i,j-1,s);
            }
        }
        return true;
    }
};

// TC->O(N)
// SC->O(1)