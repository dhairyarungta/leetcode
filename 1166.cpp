class FileSystem {
private:
    map<string, int> mp;

public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        size_t pos = path.rfind('/');
        if (pos==0 && mp.count(path)==0)
        {   
            mp[path] = value;
            return true;
        }



        if(mp.count(path)>0 || mp.count(path.substr(0,path.rfind('/')))==0)
            return false;
        else 
             mp[path]= value;
             return true;
    }
    
    int get(string path) {
        if(mp.count(path)>0)
        {
            return mp[path];
        }
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */