#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
         if(root==NULL) return root;
         queue<Node*>q;
         q.push(root);
         while(!q.empty()) {
             int sz=q.size();
             if(sz==0) return root;
             while(sz!=0) {
                 Node*temp;
                 if(sz>1) {
                    temp=q.front();
                    q.pop();
                    Node*add=q.front();
                    temp->next=add;
                 }
                 else{
                     temp=q.front();
                     q.pop();
                 }
                 if(temp->left) q.push(temp->left);
                 if(temp->right) q.push(temp->right);
                 sz--;
             }
         }
         return root;
    }
};














