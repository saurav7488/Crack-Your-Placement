#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    int fun() {
          while(!s1.empty()) {
             s2.push(s1.top());
             s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()) {
             s1.push(s2.top());
             s2.pop();
        }
        return ans;
    }
    int pop() {
       int ans =fun();
       return ans;
    }
    
    int peek() {
                 while(!s1.empty()) {
             s2.push(s1.top());
             s1.pop();
        }
        int ans=s2.top();
        // s2.pop();
        while(!s2.empty()) {
             s1.push(s2.top());
             s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        // cout<<s1.size();
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */