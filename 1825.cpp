class MKAverage {
    long sum = 0;
    int m , k , sz , pos;
    multiset<int>left,right, mid;
    vector<int>v;
public:
    void remove(int n){
        if(n<= *rbegin(left))
            left.erase(left.find(n));
        else if(n<=*rbegin(mid)){
            auto it = mid.find(n);
            sum-=*it;
            mid.erase(it);
        }
        else 
            right.erase(right.find(n));
        
        if(left.size()<k){
            left.insert(*begin(mid));
            sum -= *begin(mid);
            mid.erase(begin(mid));
        }
        if(mid.size()<sz){
            mid.insert(*begin(right));
            sum +=*begin(right);
            right.erase(begin(right)); 
        }
    }

    void add(int n){
        left.insert(n);
        if(left.size()>k){
            auto it = prev(end(left));
            mid.insert(*it);
            sum+=*it;
            left.erase(it);
        }
        if(mid.size()>sz){
            auto it = prev(end(mid));
            sum -= *it;
            right.insert(*it);
            mid.erase(it);
        }
    }

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sz = m-(2*k);
        pos = 0;
        v = vector<int>(m);
    }
    
    void addElement(int num) {
        if(pos>=m){
            remove(v[pos%m]);
        }
        add(num);
        v[pos++%m] = num;
    }
    
    int calculateMKAverage() {  
        if(pos<m)
            return -1;
        return sum/sz;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
