class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail =0 ;
        curSize = 0;
        cap =k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        data[tail] = value; 
        tail = (tail+1)%cap;
        curSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head+1)%cap;
        curSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[head]; 
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return data[(tail-1+cap)%cap];

    }
    
    bool isEmpty() {
        if(curSize==0) return true;
        return false;
    }
    
    bool isFull() {
        if(curSize == cap) return true;
        return false;
    }
private:
    vector<int> data;
    int head ;
    int tail;
    int curSize ;
    int cap;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
