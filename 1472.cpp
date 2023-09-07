class BrowserHistory {
private:
    vector<string> vec;
    vector<string>::iterator it ;

public:
    BrowserHistory(string homepage) 
        :vec{homepage}, it(vec.begin())
    {
        // cout<<*it;
    }
    
    void visit(string url) {
         it++;
        if(it!=vec.end())
             vec.erase(it,vec.end());
        vec.push_back(url);
        it= vec.end();
        it--;
        cout<<*it;
        cout<<vec.size()<<" ";
    }
    
    string back(int steps) {
        // cout<<vec.size();
        // cout<<*(it-steps);
        // cout<<it-vec.begin()<<" ";
        if((it-vec.begin())>=steps)
        {   
            cout<<"in"<<" ";
            it -=steps ;
        }
        else 
        {
            // cout<<"here";
            it = vec.begin();
        }
            

        return *it;

    }
    
    string forward(int steps) {
        if(it+steps<vec.end())
            it+=steps;
        else 
            it = --vec.end();

            return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */