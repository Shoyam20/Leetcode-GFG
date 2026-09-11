class MinStack {
public:
    vector<int> arr;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(arr.size()==0) arr.push_back(value);
        else if(arr[arr.size()-1] >=value) arr.push_back(value);
        st.push(value);
    }
    
    void pop() {
        
        if(st.size()==0)
        return ;
        int el=st.top();
        if(arr[arr.size()-1]==el) arr.pop_back();
        st.pop();

    }
    
    int top() {
        if(st.size()!=0) return st.top();
        return -1;
    }
    
    int getMin() {
         if(arr.size()!=0) return arr[arr.size()-1];
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */