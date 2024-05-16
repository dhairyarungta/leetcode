class MyCircularDeque {
    std::vector<int>dq;
    int head = 0;
    int tail = 0;
    int size = 0;
    int capacity; 
public: MyCircularDeque(int k) {
        dq.resize(k);
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull())        
            return false;
        size++;
        if(size==1){
            dq[head]=value;
        }
        else{
            if(head==0){
                head = capacity-1;
            }
            else{
                head--;
            }
            dq[head] = value;
        }

        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull())        
            return false;

        size++;
        if(size==1){
            dq[tail] = value;
        }
        else {
            tail = (tail+1)%capacity;
            dq[tail] = value; 
        }
        return true;
    }

    
    bool deleteFront() {
        if(isEmpty())        
            return false;
        size--;
        if(size!=0)
            head = (head+1)%capacity;

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())        
            return false;
        size--;
        if(size!=0){
            if(tail==0){
                tail = capacity-1;
            }
            else {
                tail--;
            }
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())     
            return -1;
        else 
            return dq[head];
    }
    
    int getRear() {
        if(isEmpty())     
            return -1;
        else 
            return dq[tail];
    }
    bool isEmpty(){
        if(size==0)              
            return true;
        else 
            return false;
    }
    
    bool isFull() {
        if(size==capacity) 
            return true;
        else 
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
