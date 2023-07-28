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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL or left==right) return head;
         ListNode*dummy=new ListNode(-1);
         ListNode*tmp=dummy;
         tmp->next=head;
         ListNode*prev_left=tmp,*l=tmp,*next_right=tmp,*r=tmp;
         int ct=0;
         while(l){
              if(ct==left) break;
              prev_left=l;
              l=l->next;
             ct++;
         }
         ct=0;
         while(r){
              if(ct==right) break;
              r=r->next;
              if(r->next==NULL){
                  next_right=NULL;
              }
             else next_right=r->next;ct++;
         }
        prev_left->next=NULL;
        r->next=NULL;
        ListNode*prev=NULL,*curr=l,*n;
        while(curr) {
             n=curr->next;
             curr->next=prev;
             prev=curr;
             curr=n;
        }
        prev_left->next=prev;
        while(prev_left->next) {
             prev_left=prev_left->next;
        }
        prev_left->next=next_right;
        return dummy->next;
    }
};