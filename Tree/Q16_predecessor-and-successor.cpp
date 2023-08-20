#include<bits/stdc++.h>
using namespace std;
// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    int r1=0,r2=INT_MAX,r3=0,r4=0;
    void fun(Node*root,int key) {
         if(root==NULL) return;
         fun(root->left,key);
         int res=root->key-key;
         if(res>0 and res<r2) {
            //  cout<<res<<" "<<root->key<<"\n";
               r1=root->key;
               r2=res;
         }
         else if(res<0 and res<r3 ) {
              r3=root->key;
              r4=res;
         }
         fun(root->right,key);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        fun(root,key);
        if(r3!=0)
        pre=new Node(r3);
        else pre=new Node(-1);
        if(r1!=0)
        suc=new Node(r1);
        else suc=new Node(-1);
    }
};