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
    int total=0;
    // void fathsum(TreeNode*root,int target,long long curr) {
    //      if(root==NULL) return;
    //      curr=curr+root->val;
    //      if(curr==target) total++;
    //      fathsum(root->left,target,curr);
    //      fathsum(root->right,target,curr);
    // }
    map<long long,long long>m;
    void fun(TreeNode*root,int tar,long long curr) {
         if(root==NULL) return;
         curr=curr+root->val;
         if(curr==tar) total++;
         total+=m[curr-tar];
         m[curr]++;
         fun(root->left,tar,curr);
         fun(root->right,tar,curr); 
         m[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
         if(root==NULL) return 0;
        //  fathsum(root,targetSum,0);
        //  pathSum(root->left,targetSum);
        //  pathSum(root->right,targetSum);
        fun(root,targetSum,0);
         return total;
    }
};















