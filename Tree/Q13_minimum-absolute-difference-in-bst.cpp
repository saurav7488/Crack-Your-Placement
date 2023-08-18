#include<bits/stdc++.h>
using namespace std;
///**
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
    int prev=-100000,ans=INT_MAX;
    void fun(TreeNode*root) { 
          if(root==NULL) return;  
          fun(root->left);
          ans=min(ans,abs(root->val-prev));
          prev=root->val;
          fun(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
         fun(root);
         return ans;
    }
};
















