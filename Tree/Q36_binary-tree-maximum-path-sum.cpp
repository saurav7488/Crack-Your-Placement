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
    int maxi=INT_MIN;
    int fun(TreeNode*root) {
         if(root==NULL) return 0;
         int l=fun(root->left);
         int r=fun(root->right);
         int a=max(root->val,max(l,r)+root->val);
         int b=max(a,root->val+l+r);
         maxi=max(maxi,b);
         return a;
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return maxi;
    }
};