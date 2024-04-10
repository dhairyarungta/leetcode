class Allocator {
public:
    std::unordered_map<int,std::vector<pair<int,int>>>usedMem; //mId, index, size
    std::map<int,int>freeMem;//index, size
    

    Allocator(int n) {
        
        freeMem.insert({0,n});
    }
    
    int allocate(int size, int mID) {
        for(auto it = freeMem.begin();it!=freeMem.end();it++){
            if(it->second==size){
                int returnIndex = it->first;
                freeMem.erase(it);
                usedMem[mID].push_back({returnIndex,size});
                return returnIndex;
            }
            else if(it->second>size){
                int returnIndex = it->first;
                int newSize = it->second-size;
                freeMem.erase(it);
                freeMem.insert({returnIndex+size,newSize});
                usedMem[mID].push_back({returnIndex,size});
                return returnIndex;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int sz =0;
        if(usedMem.find(mID)==usedMem.end()){
            return 0;
        }
        else{
            auto it1 = usedMem.find(mID);
            for(auto e : it1->second){
                auto ita = freeMem.insert({e.first,e.second}).first;
                if (ita != begin(freeMem)) {
                if (auto p = prev(ita); p->first + p->second == e.first) {
                    p->second += e.second;
                    freeMem.erase(ita);
                    ita = p;
                }
            }
            if (next(ita) != end(freeMem)) {
                if (auto n = next(ita); e.first + e.second == n->first) {
                    ita->second += n->second;
                    freeMem.erase(n);
                }
            }
                sz+=e.second;
            }
        }
        usedMem.erase(mID);
        return sz;
        
    }


};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
