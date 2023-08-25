//**
 // Definition for a binary tree node.
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
    void fun(TreeNode*root,TreeNode*&first,TreeNode*&prev,TreeNode*&end) {
         if(root==NULL) return;
         fun(root->left,first,prev,end);
         if(prev!=NULL) {
              if(root->val<prev->val) {
                   if(first==NULL) first=prev;
                   end=root;
              }
         }
         prev=root;
         fun(root->right,first,prev,end);
    }
    void recoverTree(TreeNode* root) {
        TreeNode*first=NULL,*prev=NULL,*end=NULL;
        fun(root,first,prev,end);
        swap(first->val,end->val);
    }
};














