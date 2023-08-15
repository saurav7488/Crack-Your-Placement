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
    void fun(TreeNode*root,vector<string>&ans,string tmp) {
          if(root==NULL) return;
          tmp+=to_string(root->val);
          if(root->left==NULL and root->right==NULL) {
               ans.push_back(tmp);
          }
          if(root->left or root->right) tmp+="->";
          fun(root->left,ans,tmp);
          fun(root->right,ans,tmp);
          tmp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string tmp;
        fun(root,ans,tmp);
        return ans;
    }
};











