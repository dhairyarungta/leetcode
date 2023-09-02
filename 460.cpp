class LFUCache {
private:
    int cap ;
    int size ;
    int minFreq;
    unordered_map<int, pair<int,int>> m; //key, {value, frequency}
    unordered_map<int,list<int>::iterator>mIter;
    unordered_map<int,list<int>>fm;


public:
    LFUCache(int capacity):cap(capacity),size(0) {
        
    }
    
    int get(int key) {
        if(m.count(key)==0) 
            return -1;
        
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key] = --fm[m[key].second].end();

        if(fm[minFreq].size ()==0)
        {
            minFreq++;

        }
        return m[key].first;

    }
    
    void put(int key, int value) {
        if(cap<=0) return;

        int flag = get(key);
        if(flag!=-1)
        {
            m[key].first =value;
            return ;

        }
        if(size>=cap)
        {
            int evictedKey = fm[minFreq].front();
            fm[minFreq].pop_front();
            if(fm[minFreq].size()==0)
                fm.erase(minFreq);
            
            m.erase(evictedKey);
            mIter.erase(evictedKey);
        }
        


        fm[1].push_back(key);
        mIter.insert({key,--fm[1].end()});
        m.insert({key,{value,1}});
        minFreq = 1;
        size++;

        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */