#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
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
    bool fun(TreeNode*root,int sum) {
         if(root==NULL) return false;
        //  if(sum<0) return false;
         if(!root->left and !root->right and root->val==sum) return true;
         bool a=fun(root->left,sum-root->val);
         bool b=fun(root->right,sum-root->val);
         return a+b;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root,targetSum);
    }
};









