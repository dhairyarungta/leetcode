class MovingAverage {
private: 
    std::deque<int> dq;
    int size ;
    double current_sum;
public:
    MovingAverage(int size):size(size),current_sum(0) {
        
    }
    
    double next(int val) {
       if(dq.size()>=size)
       {   
           int remove_val = dq.front();
           dq.pop_front();
           current_sum-=remove_val;
           current_sum+=val;
           dq.push_back(val);
       }else
       {
           dq.push_back(val) ;
           current_sum+=val; 
       } 
        return (current_sum/dq.size())  ;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

