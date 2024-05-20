class MyHashSet {
    int sz = 0;
    vector<list<int>>vec;//list<key>
    void rehash(){
        vector<list<int>>a (2*vec.size());
        for(int i = 0;i<vec.size();i++){
            for(auto it = vec[i].begin(); it!=vec[i].end();it++){
                int newIdx = (*it)%a.size();
                a[newIdx].splice(a[newIdx].end(),vec[i],it);
            }
        }
        
        vec = std::move(a);
    }
public:
    MyHashSet() {
        vec = vector<list<int>>(1000);
    }
    
    void add(int key) {
        if(contains(key))
            return ;

        sz++;
        double val = ((double)sz)/vec.size();      
        if(val > 0.7){
            // rehash();
        }
        int idx = key%vec.size(); 
        vec[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = key%vec.size();
        for( auto it= vec[idx].begin(); it!=vec[idx].end();it++){
            if(*it == key){
               vec[idx].erase(it); 
               sz--;
               break;
            }
        }

    }
    
    bool contains(int key) {
        int idx = key%vec.size(); 
        for(auto it : vec[idx]){
            if(it == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
