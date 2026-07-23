class MinStack {
    stack<long long int > st;
    long long minval;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minval = value;
            return;
        }
        if(value < minval){
            st.push(2LL * value - minval);
            minval = value;
        }else{
            st.push(value);
        }
        
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        if(st.top() < minval){
            minval = 2 * minval - st.top();
            st.pop();
        }else{
            st.pop();
        }
        
    }
    
    int top() {
        if(st.top() < minval)
        return minval;
        return st.top();
    }
    
    int getMin() {
        return minval;
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