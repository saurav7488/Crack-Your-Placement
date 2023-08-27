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
 
 // TC - > O(N)*Log(N)
 // SC -> (N)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
           vector<vector<int>>ans;
           map<int,map<int,multiset<int>>>m;
           queue<pair<TreeNode*,pair<int,int>>>q;
           q.push({root,{0,0}});
           while(!q.empty()) {
                   TreeNode*node=q.front().first;
                   int x=q.front().second.first;
                   int y=q.front().second.second;
                   q.pop();
                   m[x][y].insert(node->val);
                   if(node->left) {
                       q.push({node->left,{x-1,y+1}});
                   }
                   if(node->right) {
                       q.push({node->right,{x+1,y+1}});
                   }
           }
           for(auto it:m) {
                vector<int>col;
               for(auto i:it.second) {
                    for(auto j:i.second) {
                        col.push_back(j);
                    }
               }
               ans.push_back(col);
           }
           return ans;
    }
};




















