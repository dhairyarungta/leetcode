class LogSystem {
public:
    unordered_map<string,int>lengths = {{"Year",4},{"Month",7},{"Day",10},{"Hour",13},{"Minute",16},{"Second",19}} ;
    unordered_map<string,string>mpStart = 
     {{"Year",":01:01:00:00:00"},{"Month",":01:00:00:00"},{"Day",":00:00:00"},{"Hour","00:00"},{"Minute",":00"},{"Second",""}} ;
    unordered_map<string,string>mpEnd =
     {{"Year",":12:31:23:59:59"},{"Month",":31:23:59:59"},{"Day",":23:59:59"},{"Hour",":59:59"},{"Minute",":59"},{"Second",""}} ;

    map<string,int>logStore;
    LogSystem() {

    }
    
    void put(int id, string timestamp) {
        logStore[timestamp] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int len = lengths[granularity];
        string startSuffix = mpStart[granularity];
        string endSuffix = mpEnd[granularity];
        string s= start.substr(0,len)+startSuffix;
        string e = end.substr(0,len)+endSuffix;
        vector<int>ans;
        auto itrStart = logStore.lower_bound(s);
        auto itrEnd = logStore.upper_bound(e);
        for(auto it = itrStart; it!=itrEnd;it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
