class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        int curr=value;
        if(!st.empty())
        {
            curr=min(value,st.top().second);
        }
        st.push({value,curr});
       
    }
    
    void pop() {
        st.pop(); 
    }
    
    int top() {
return st.top().first;
    }
    
    int getMin() {
       return st.top().second;
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