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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode*temp=head;
         while(temp and temp->next) {
              if(temp->val==temp->next->val) {
                   while(temp and temp->next and temp->val==temp->next->val) {
                        ListNode*p=temp->next;
                        temp->next=p->next;
                        delete p;
                   }
              }
              temp=temp->next;
          }
          return head;
    }
};
