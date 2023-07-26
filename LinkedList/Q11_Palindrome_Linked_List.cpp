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
    bool isPalindrome(ListNode* head) {
        ListNode*s=head,*f=head;
        while(f and f->next) {
            s=s->next;
            f=f->next->next;
        }
        ListNode*prev=NULL,*curr=s,*fast=s->next;
        while(curr) {
             curr->next=prev;
             prev=curr;
             curr=fast;
             if(fast) fast=fast->next;
        }
        while(head and prev) {
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};















