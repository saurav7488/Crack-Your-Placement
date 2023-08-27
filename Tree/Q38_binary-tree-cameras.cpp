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
    int monitored=-1,iscamera=0,needcamera=1;
    int fun(TreeNode*root,int&count) {
         if(root==NULL) return monitored;
         int l=fun(root->left,count);
         int r=fun(root->right,count);
         if(l==needcamera or  r==needcamera) {
              count++;
              return iscamera;
         }
         else if(l==iscamera or r==iscamera) return monitored;
         return needcamera;
    }
    int minCameraCover(TreeNode* root) {
         int count=0;
         int res=fun(root,count);
         if(res==needcamera) count++;
         return count;
    }
};


























