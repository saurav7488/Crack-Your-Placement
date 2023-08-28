#include<bits/stdc++.h>
using namespace std;
//**
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reverse(ListNode*s,ListNode*e) { 
         ListNode*prev=NULL,*curr=s,*n=s->next;
         while(prev!=e) {
             curr->next=prev;
             prev=curr;
             curr=n;
             if(n) n=n->next;
         }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k<2 or head->next==NULL) return head;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*s=dummy,*e=head;
        int i=0;
        while(e) {
            i++;
            if(i%k==0) {
                 ListNode*ss=s->next,*tmp=e->next;
                 reverse(s,e);
                 s->next=e;
                 ss->next=tmp;
                 s=ss;
                 e=tmp;
            }
            else
            e=e->next;
        }
        return dummy->next;
    }
};
























