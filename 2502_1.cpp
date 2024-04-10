//brute force solution
class Allocator {
public:
    int a[1001] = {0};
    int capacity;
    Allocator(int n) : capacity(n){
            
    }
    
    int allocate(int size, int mID) {
        int curCount = 0;
        for(int i =0;i<capacity;i++) {
            if(a[i]==0){
                curCount++;
                if(curCount==size){
                    for(int j = i-curCount+1;j<=i;j++){
                        a[j] = mID;
                    }   
                    return i-curCount+1;
                }
            }
            else {
                curCount = 0;
            }
        }   
        return -1;
    }
    
    int free(int mID) {
        int memory = 0;
       for(int i =0;i<capacity;i++){
        if(a[i]==mID){
            memory++;
            a[i] = 0;
        }
       } 
       return memory;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
