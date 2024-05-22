class StringIterator {
    string comp;
    char cur ;
    int left ;
    int index ;
public:
    StringIterator(string compressedString) : comp(compressedString) {
        
        index = 0;
        cur = comp[0]; 
        index++;
        string count {""};
        while(index< comp.size() &&comp[index]<='9' && comp[index]>='0'){
            count.push_back(comp[index]);
            index++;
        }
        
        left = stoi(count); 
    }
    
    char next() {
        if(left == 0 && index == comp.size())
            return ' ';

        if(left==0){
            cur = comp[index++]; 
            string count {""};
            while(index< comp.size() && comp[index]<='9' && comp[index]>='0'){
                count.push_back(comp[index]);
                index++;
            }
            left = stoi(count); 
        }    
        left--;
        return cur; 
    }
    
    bool hasNext() {
        if(index>=comp.size() && left == 0)
            return false;
        return true;
    }

};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
