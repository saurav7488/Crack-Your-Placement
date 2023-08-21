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
    vector<int>ans;
    void fun(TreeNode*root,int i) {
        if(root==NULL) return;
        if(i==ans.size()) ans.push_back(root->val);
        fun(root->right,i+1);
        fun(root->left,i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        fun(root,0);
        return ans;
    }
};















