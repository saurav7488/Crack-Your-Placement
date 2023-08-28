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
    ListNode* partition(ListNode* head, int x) {
          ListNode*curr=new ListNode(-1);
          ListNode*tail=curr,*tmp=head;
          while(tmp) {
               if(tmp->val<x) {
                    tail->next=new ListNode(tmp->val);
                    tail=tail->next;
               }
               tmp=tmp->next;
          }
          tmp=head;
          while(tmp) {
               if(tmp->val>=x) {
                    tail->next=new ListNode(tmp->val);
                    tail=tail->next;
               }
               tmp=tmp->next;
          }
          return curr->next;
    }
};













