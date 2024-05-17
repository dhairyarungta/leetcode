class TextEditor {
    deque<char>left;
    deque<char>right;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        int n = text.size(); 
        for(auto c :text){
            left.push_back(c);
        }
    }
    
    int deleteText(int k) {
        int n = 0;
        while(k-- && !left.empty()){
            left.pop_back();            
            n++;
        }
        return n; 
    }
    
    string cursorLeft(int k) {
        
        while(k-- && !left.empty()){
            right.push_front(left.back());
            left.pop_back();
        }
        int i = 10;
        auto it = left.rbegin();
        string s{""}; 
        while(i-- && it!=left.rend()){
            s.push_back(*it);
            it++;
        }
        std::reverse(s.begin(),s.end());
        return s;
    }
    
    string cursorRight(int k) {
        while(k-- && !right.empty()){
            left.push_back(right.front());
            right.pop_front();
        }
        int i = 10;
        auto it = left.rbegin();
        string s{""}; 
        while(i-- && it!=left.rend()){
            s.push_back(*it);
            it++;
        }
        std::reverse(s.begin(),s.end());
        return s;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
