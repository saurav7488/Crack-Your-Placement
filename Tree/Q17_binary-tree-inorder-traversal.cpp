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
    void dfs(TreeNode*root,vector<int>&ans){ 
        if(root==NULL)
            return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       // vector<int>ans;
       // dfs(root,ans);
       // return ans;
       vector<int>in;
       stack<TreeNode*>st;
       TreeNode*node=root;
       while(1) {
            if(node) {
                 st.push(node);
                 node=node->left;
            }
            else{
                 if(st.empty()) break;
                 node=st.top();
                 st.pop();
                 in.push_back(node->val);
                 node=node->right;
            }
       }
       return in;
    }
    
};














