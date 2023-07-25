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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode*prev=NULL,*curr=head,*fast=head->next;
        while(curr) {
            curr->next=prev;
            prev=curr;
            curr=fast;
            if(fast) fast=fast->next;
        }
        return prev;
    }
};
// tc->O(n)
// sc->O(1)


