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
    int multiplyLinkedListNodes(ListNode* l1, ListNode* l2) {
          int num1=0;
          int num2=0;
          while(l1 or l2) {
              if(l1) {
                   num1=num1*10+l1->val;
                   l1=l1->next;
              }
              if(l2) {
                  num2=num2*10+l2->val;
                  l2=l2->next;
              }
          }
          return num1*num2;
    }
};


