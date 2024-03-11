class SeatManager {
private: 
    std::set<int>st;
public:
    SeatManager(int n) {
       while(n>0) 
       {
           st.insert(n);
           n--;
       } 

    }
    
    int reserve() {
       auto node = (st.extract(st.cbegin())) ;
       int min_value = node.value();
       return min_value;
    }
    
    void unreserve(int seatNumber) {
       st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
