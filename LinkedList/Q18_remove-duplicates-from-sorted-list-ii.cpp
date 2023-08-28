#include<bits/stdc++.h>
using namespace std;
///**
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
    ListNode* deleteDuplicates(ListNode* tmp) {
         ListNode*dumm=new ListNode(-1,tmp);
          ListNode*ans=dumm;
         while(tmp) {
              if(tmp->next!=NULL and tmp->val==tmp->next->val) {
                   while(tmp->next!=NULL and tmp->val==tmp->next->val) {
                        tmp=tmp->next;
                   }
                  ans->next=tmp->next;
              }
             else{
                  ans=ans->next;
             }
             tmp=tmp->next;
         }
        return dumm->next;
    }
};

























