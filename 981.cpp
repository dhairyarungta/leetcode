class TimeMap {
private: 
    std::unordered_map<string,vector<pair<int, string>>>mp;
    static bool comp(const pair<int,string> &a, const pair<int,string> &b){
        /*value,iter*/
        if(b.first<a.first)return false;
        else return true;
        //lower_bound stops when comp returns true
    } 
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value}) ;    
    }
    
    string get(string key, int timestamp) {
        if(mp.contains(key)==false)
            return "";
        std::pair<int,string>test(timestamp,"test"); 
        auto it = std::lower_bound(mp[key].begin(),mp[key].end(),test,comp);
        if(it == mp[key].begin())
            return "";
        else{
            auto it_return = std::prev(it);
            return (it_return->second);            
        }
        }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
