#include<bits/stdc++.h>
using namespace std;

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
    int diameter(TreeNode*root,int &mini) {
         if(root==NULL) return 0;
         int right=diameter(root->right,mini);
         int left=diameter(root->left,mini);
         mini=max(mini,(left+right));
         return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mini=0;
        diameter(root,mini);
        return mini;
    }
};


