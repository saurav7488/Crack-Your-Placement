#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode*reverse(ListNode*a) {
         ListNode*prev=NULL,*curr=a,*fast=a->next;
         while(curr) {
             curr->next=prev;
             prev=curr;
             curr=fast;
             if(fast) fast=fast->next;
         }
         return prev;
    }
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode*l1=reverse(a);
        ListNode*l2=reverse(b);
        ListNode*temp=new ListNode(-1);
        ListNode*curr=temp;
        int carry=0;
        while(l1 or l2 or carry) {
             int r1=0,r2=0;
             if(l1) r1=l1->val;            
             if(l2) r2=l2->val;
             int sum=r1+r2+carry;
             curr->next=new ListNode(sum%10);
             curr=curr->next;
             carry=sum/10;
             if(l1) l1=l1->next;
             if(l2) l2=l2->next;
        }
        ListNode*c=reverse(temp->next);
        return c;
    }
};