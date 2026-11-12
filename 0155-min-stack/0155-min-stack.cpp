class MinStack {
public:
  stack<int> st;
  stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minSt.push(value);
            return;
        }
        if(value<=minSt.top()){
            minSt.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        int num = st.top();
         st.pop();
        if(minSt.top()==num){
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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