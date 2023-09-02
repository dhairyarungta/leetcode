class LRUCache {
    const size_t m_capacity;
    unordered_map<int, list<pair<int,int>>::iterator> m_map;
    list<pair<int,int>>m_list;

public:
    LRUCache(int capacity):m_capacity(capacity) {
        
    }
    
    int get(int key) {
        auto find_iter = m_map.find(key);
        if(find_iter==m_map.end())
        {
            return -1;
        }
        m_list.splice(m_list.begin(),m_list,find_iter->second);
        return find_iter->second->second;

    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if(found_iter!=m_map.end())
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
            return;
        }
        if(m_list.size()>=m_capacity)
        {
            m_map.erase(m_list.back().first);
            m_list.pop_back();
        }

        m_list.push_front({key,value});
        m_map.insert({key,m_list.begin()});
        return ;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */