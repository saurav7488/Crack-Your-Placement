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
    ListNode*middle(ListNode*head) {
         if(head==NULL) return NULL;
         ListNode*slow=head,*fast=head;
         while(fast->next and fast->next->next) {
               slow=slow->next;
               fast=fast->next->next;
         }
         return slow;
    } 
    ListNode*mergesortList(ListNode*a,ListNode*b) {
          if(!a) return b;
          if(!b) return a;
          ListNode*ans=new ListNode(0);
          ListNode*curr=ans;
          while(a and b) {
             if(a->val<b->val) {
                 curr->next=a;
                 a=a->next;
             }
             else {
                  curr->next=b;
                  b=b->next;
             }
             curr=curr->next;
          } 
          if(a) curr->next=a;
          if(b) curr->next=b;
          return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode*mid=middle(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*Left_side=sortList(head);
        ListNode*right_side=sortList(right);
        return mergesortList(Left_side,right_side);
    }
};


