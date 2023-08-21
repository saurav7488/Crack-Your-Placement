#include<bits/stdc++.h>
using namespace std;
//**
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  class Solution {
  public:
      void find_parent(map<TreeNode*,TreeNode*>&m,TreeNode*root,TreeNode*par) {
         if(root==NULL) return;
         m[root]=par;
         find_parent(m,root->left,root);
         find_parent(m,root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          map<TreeNode*,TreeNode*>m;
          map<TreeNode*,bool>vis;
          find_parent(m,root,NULL);
           queue<TreeNode*>q;
           q.push(target);
           vis[target]=true;
           while(!q.empty() and k>0) {
                int sz=q.size();
                while(sz--) {
                    TreeNode*num=q.front();
                    q.pop();
                    if(num->left and !vis[num->left]) {
                        q.push(num->left);
                        vis[num->left]=true;
                    }
                    if(num->right and !vis[num->right]) {
                        q.push(num->right);
                        vis[num->right]=true;
                    }
                    if(m[num] and !vis[m[num]]) {
                         q.push(m[num]);
                         vis[m[num]]=true;
                    }
                }
                k--;
           }
           vector<int>ans;
           while(!q.empty()) {
               ans.push_back(q.front()->val);
               q.pop();
           }
           cout<<q.size();
          return ans;
    }
};
































