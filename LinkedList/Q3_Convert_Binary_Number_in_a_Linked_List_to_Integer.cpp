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
    int getDecimalValue(ListNode* head) {
        ListNode*temp=head;
        int cnt=0,ans=0;
        while(temp) {
            cnt++;
            temp=temp->next;
        }
        temp=head;
        cnt--;
        while(temp) {
             if(temp->val) {
                  ans+=pow(2,cnt);
             }
             cnt--;
             temp=temp->next;
        }
        return ans;
     }
};