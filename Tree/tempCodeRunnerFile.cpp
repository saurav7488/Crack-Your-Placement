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
    bool fun(TreeNode*root,long int min,long int max) {
         if(root==NULL) return true;
         if(root->val>min and root->val<max) {
              bool a=fun(root->left,min,root->val);
              bool b=fun(root->right,root->val,max);
              return a and b;
         }
         return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(!root->left and !root->right) return true;
        return fun(root,LONG_MIN,LONG_MAX);
    }
};
   














