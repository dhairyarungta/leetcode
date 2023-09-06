class MinStack {
private :
    vector<int> vec;
    vector<int> minVec;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        if(minVec.empty()||val<=minVec.back()  )
            minVec.push_back(val);
    }
    
    void pop() {
        if(vec.back()==minVec.back())
        minVec.pop_back();
        vec.pop_back();
    }
    
    int top() {
        int val = vec.back();
        return val;
    }
    
    int getMin() {
        return minVec.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */