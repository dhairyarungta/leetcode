class HitCounter {
private:
    vector<int> vec{};


public:

    HitCounter(){

    }
    
    void hit(int timestamp) {
        vec.push_back(timestamp);
        return ;

    }
    
    int getHits(int timestamp) {
        if(vec.size()==0)
            return 0;
        else {
            auto index = upper_bound(vec.begin(), vec.end(), timestamp-300);
            return (vec.end()-index);
        }
            
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */`



 //using queue 
 class HitCounter {
    queue<int> hits;

public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!hits.empty()){
            if(hits.front()<=(timestamp-300)){
                hits.pop();
            }
            else{
                break;
            } 
        }
        return hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */