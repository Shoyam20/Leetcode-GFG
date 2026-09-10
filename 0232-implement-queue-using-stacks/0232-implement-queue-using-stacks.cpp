class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        int s1s=st1.size();
        for(int i=0;i<s1s;i++)
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        for(int i=0;i<s1s;i++)
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int el=st1.top();
        st1.pop();
        return el;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        int s=st1.size();
        if(s==0)return true;
        return false;
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