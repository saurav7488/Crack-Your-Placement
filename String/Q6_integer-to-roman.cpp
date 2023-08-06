#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fun(int num) {
         if(num<4) {
             string ans="";
             for(int i=1;i<=num;i++) {
                 ans+="I";
             }
             return ans;
         }
         if(num>=1000) {
               return "M"+fun(num-1000);
         }
         else if(num>=900) {
             return "CM"+fun(num-900);
         }
         else if(num>=500) {
             return "D"+fun(num-500);
         }
         else if(num>=400) {
              return "CD"+fun(num-400);
         }
         else if(num>=100) {
              return "C"+fun(num-100);
         }
         else if(num>=90) {
              return "XC"+fun(num-90);
         }
         else if(num>=50) {
              return "L"+fun(num-50);
         }
         else if(num>=40) {
              return "XL"+fun(num-40);
         }
         else if(num>=10) return "X"+fun(num-10);
         else if(num>=9) {
              return "IX"+fun(num-9);
         }
         else if(num>=5) {
              return "V"+fun(num-5);
         }
         return "IV"+fun(num-4);
    }
    string intToRoman(int num) {
        return fun(num);
    }
};


// TC->O(N)
// SC->O(1)