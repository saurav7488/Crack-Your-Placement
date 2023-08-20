#include<bits/stdc++.h>
using namespace std;
//*The Node structure is
struct Node {
int data;
Node * right, * left;
};

/*You are required to complete below method */
    //         8 (1,inf)
            
    //     5(1,7)      9(9,inf)
        
    // 2(1,4)      7(9,8) 
    
    // 1(1,1)
bool fun(Node*root,int mini,int maxi) {
      if(root==NULL) return false;
      if(mini==maxi) return true;
      return fun(root->left,mini,root->data-1) or fun(root->right,root->data+1,maxi);
}
bool isDeadEnd(Node *root)
{    int mini=1,maxi=INT_MAX;
     return fun(root,mini,maxi);
}