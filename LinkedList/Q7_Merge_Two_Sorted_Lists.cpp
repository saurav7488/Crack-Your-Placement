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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // using iteration

        // if(l1==NULL) return l2;
        // if(l2==NULL) return l1;
        // ListNode*tail,*head;
        // if(l1->val<l2->val) {
        //     tail=l1;
        //     head=l1;
        //     l1=l1->next;
        // }
        // else{
        //     tail=l2;
        //     head=l2;
        //     l2=l2->next;
        // }
        // while(l1 and l2) { 
        //      if(l1->val<l2->val) {
        //           tail->next=l1;
        //           tail=l1;
        //           l1=l1->next;
        //      }
        //      else{
        //          tail->next=l2;
        //          tail=l2;
        //          l2=l2->next;
        //      }
        // }
        // if(l1) tail->next=l1;
        // else tail->next=l2;
        // return head;



       // using recursion
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val) {
             l1->next=mergeTwoLists(l1->next,l2);
             return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        return l1;
    }
};