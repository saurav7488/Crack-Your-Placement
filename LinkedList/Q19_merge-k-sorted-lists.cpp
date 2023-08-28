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
 
 class cmp {
      public:
      bool  operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
      }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
         for(int i=0;i<lists.size();i++) {
              if(lists[i]) pq.push(lists[i]);
         }
         ListNode*dummy=new ListNode(-1);
         ListNode*mov=dummy;
         while(!pq.empty()) {
              ListNode*curr=pq.top();
              pq.pop();
              mov->next=curr;
              mov=curr;
              if(curr->next) pq.push(curr->next);
         }
         return dummy->next;
    }
};















