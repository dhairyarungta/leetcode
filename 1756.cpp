class MRUQueue {
    list<int> num;
    int size;
    vector<std::list<int>::iterator>vec;
public:
    MRUQueue(int n) {
       size = sqrt(n);
       for (int i =0;i<=n;i++){
                num.push_back(i);
                if(i%size==0){
                    vec.push_back(prev(num.end()));
                }
        } 
    }
    
    int fetch(int k) {
        int idx = k/size;
        k =k%size;
        auto it = vec[idx];
        for (;k>0;k--,it++);

        if(next(it)==num.end()) 
            return *it;

        int return_val = *it;
        if(vec[idx]==it)
            vec[idx] = next(vec[idx]);
        for (int i = idx+1;i<vec.size();i++){
            vec[i]=next(vec[i]);            
        }
//          cout<<endl;
//  for (int i =0;i<vec.size();i++) {
//      cout<<*vec[i]<<" ";
//  }
//  cout<<endl;
        bool check = false;
        if(vec.back()==num.end()) 
            check =true; 
        num.splice(num.end(),num,it);
        if(check ==true) 
            vec.back() = it;
 //       cout<<"list";
 //       for (auto it :num){
 //           cout<<it<<" ";
 //       } 
 //       cout<<endl;
 //       for (int i =0;i<vec.size();i++) {
 //           cout<<*vec[i]<<" ";
 //       }
 //       cout<<endl;
        return return_val;
        
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
