#include<queue>
class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int s=q1.size();
        for(int i=0;i<s-1;i++)
        {
            int el=q1.front();
            q1.push(el);
            q1.pop();
        }
    }
    
    int pop() {
        int el=q1.front();
        q1.pop();
        return el;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        int s=q1.size();
        if(s==0) return true;
        return false;
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