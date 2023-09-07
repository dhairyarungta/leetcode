class RandomizedSet {
private:
    unordered_map<int, int>mp;
    vector<int> vec;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)>0)
        {
            return false;
        }

        mp[val] = vec.size();
        vec.push_back(val);
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)
        {
            return false;
        }
        int pos = mp[val];
        swap(vec[mp[val]],vec[vec.size()-1]);
        mp[vec[pos]] = pos;
        vec.pop_back();
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        int range = vec.size();
        int num = rand()%range;
        return vec[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */