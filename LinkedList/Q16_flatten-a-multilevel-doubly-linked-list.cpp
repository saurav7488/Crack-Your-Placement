#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
             Node*cur=head;
             Node*tail=head;
             stack<Node*>st;
             while(cur!=NULL) {
                  if(cur->child) {
                      Node*ch=cur->child;
                      if(cur->next) {
                          st.push(cur->next);
                          cur->next->prev=NULL;
                      }
                      cur->next=ch;
                      ch->prev=cur;
                      cur->child=NULL;
                  }
                  tail=cur;
                  cur=cur->next;
             }
             while(!st.empty()) {
                 cur=st.top();
                 st.pop();
                 tail->next=cur;
                 cur->prev=tail;
                 while(cur) {
                      tail=cur;
                      cur=cur->next;
                 }
             }
         return head;
    }
};



























