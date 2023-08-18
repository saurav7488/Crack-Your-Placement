#include<bits/stdc++.h>
using namespace std;
//**
 //* Definition for a binary tree node.
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
     int sum=0;
     void fun(TreeNode*root,bool flag) {
          if(root==NULL) return;
          fun(root->left,true);
          // cout<<root->val<<"\n";
          if(!root->left and !root->right and flag)
          sum+=root->val;
          fun(root->right,false);
     }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag=false;
        fun(root,flag);
        return sum;
    }
};