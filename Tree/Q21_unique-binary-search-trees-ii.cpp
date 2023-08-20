#include<bits/stdc++.h>
using namespace std;
//**
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<TreeNode*>fun(int s,int e) {
        vector<TreeNode*>ans;
        if(s>e) {
             ans.push_back(NULL);
             return ans;
        }
        if(s==e) {
            ans.push_back(new TreeNode(s));
            return ans;
        }
        for(int i=s;i<=e;i++) {
              auto l=fun(s,i-1);
              auto r=fun(i+1,e);
              for(auto m:l) {
                   for(auto n:r) {
                        auto it=new TreeNode(i);
                        it->left=m;
                        it->right=n;
                        ans.push_back(it);
                   }
              }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
         return fun(1,n);
    }
};


























