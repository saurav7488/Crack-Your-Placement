#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
// 1 2 3 4
    deque<int>d;
    MyStack() {
        
    }
    
    void push(int x) {
        d.push_front(x);
    }
    
    int pop() {
       int ans=d.front();
       d.pop_front();
       return ans;
    }
    
    int top() {
      return d.front();
    }
    
    bool empty() {
       return d.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */