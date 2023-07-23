#include<bits/stdc++.h>
using namespace std;
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
    void sumup(TreeNode*root,int low,int high,int& sum) {
         if(root==NULL) return;
         if(root->val>=low and root->val<=high) sum+=root->val;
         sumup(root->left,low,high,sum);
         sumup(root->right,low,high,sum);
     }
    int rangeSumBST(TreeNode* root, int low, int high) {
         int sum=0;
         sumup(root,low,high,sum);
         return sum;
    }
};

