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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL) return ans;
        q.push(root);
        int flip=0;
        while(!q.empty()) {
            int sz=q.size();
            vector<int>tmp;
            for(int i=0;i<sz;i++) {
                TreeNode*tt=q.front();
                q.pop();
                if(tt->left!=NULL) q.push(tt->left);
                if(tt->right!=NULL) q.push(tt->right);
                tmp.push_back(tt->val);
            }
            if(flip++%2) reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};














