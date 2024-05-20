class MaxStack {
    using  mitr = std::multimap<int,int>::iterator ;
    map<int,mitr>pos;//sz, val iterator
    multimap<int,int>val;//value,sz
    int sz = 0;
public:
    MaxStack() {
    }
    
    void push(int x) {
        sz++;
        auto it = val.insert({x,sz});
        pos.insert({sz,it});
    }
    
    int pop() {
        auto it = pos.rbegin();       
        int num = (it->second)->first; 
        val.erase(it->second);
        pos.erase(prev(pos.end()));
        return num; 
    }
    
    int top() {
        auto it = pos.rbegin();       
        return it->second->first;
    }
    
    int peekMax() {
        auto it = val.rbegin();
        return it->first;
        
    }
    
    int popMax() {
        auto it = val.rbegin();
        int num = it->first;
        pos.erase(it->second);
        val.erase(prev(val.end()));
        return num;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
