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
    TreeNode*fun(vector<int>&preorder,int ps,int pe,vector<int>& postorder,int s,int e) {
         if(ps>pe or s>e) return NULL;
         TreeNode*root=new TreeNode(preorder[ps]);
         if(ps==pe) return root;
         int postind=s;
         while(postorder[postind]!=preorder[ps+1]) postind++;
         int len=postind-s+1;
         root->left=fun(preorder,ps+1,ps+len,postorder,s,postind);
         root->right=fun(preorder,ps+len+1,pe,postorder,postind+1,e-1);
         return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return fun(preorder,0,preorder.size()-1,postorder,0,postorder.size());
    }
};





































