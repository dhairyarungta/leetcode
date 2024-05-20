class RandomizedCollection {
    unordered_map<int,set<int>>a;
    vector<int>v;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ret = true;
        if(a.contains(val))
            ret = false;
        int idx = v.size(); 
        a[val].insert(idx);
        v.push_back(val);
        return ret;
    }
    
    bool remove(int val) {
        if(!a.contains(val))
            return false;


        int num = v.back();
        if(num == val){
           a[val].erase(v.size()-1); 
        }
        else{
            int idx = *(a[val].begin()); 
            a[val].erase(a[val].begin());
            auto &s2 = a[num];
            a[num].erase(v.size()-1);
            a[num].insert(idx);
            std::swap(v[v.size()-1],v[idx]);
        }

        v.pop_back(); 
        if(a[val].empty()){
            a.erase(val);
        }
        return true; 
    }
    
    int getRandom() {
       int idx = rand()%v.size(); 
       return v[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
