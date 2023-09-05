class MedianFinder {

private :
    priority_queue<int, vector<int> , greater<int> >large;
    priority_queue<int>small;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(large.size()>small.size())
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size()?small.top():((double)small.top()+(double)large.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */