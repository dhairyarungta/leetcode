struct TrieNode
{
    public:
    map<string,TrieNode*> mp;
    int value = -1;
    TrieNode(int value):value(value)
    {}

};


class FileSystem {
private :
    TrieNode* root;
public:
    FileSystem() {
        root = new TrieNode(-1);
    }
    
    bool createPath(string path, int value) {
        TrieNode* parentNode = root;
        vector<string> components ;
        stringstream ss (path);
        string temp = "";
        while(getline(ss,temp,'/'))
        {   
            if(!temp.empty())
            components.push_back(temp);
        }
        // components.erase(components.begin());

        for (auto i:components)
            cout<<"i:"<<i<<"  ";
        for (int i =0 ;i<components.size();i++)
        {   
            string cur = components[i];
            if(parentNode->mp.count(cur)==0)
            {   
                // cout<<"i:"<<i<<" componentssize:"<<components.size()<<endl;
                if(i<(components.size()-1))
                {   
                    // cout<<"here";
                    return false;
                }
                else 
                {   
                    parentNode->mp.insert({cur,new TrieNode(value)});
                    return true;
                }


            }
            else 
                parentNode = parentNode->mp[cur];
        }
        
        // cout<<"here";
        return false;
    }
    
    int get(string path) {
        stringstream ss(path);
        string temp = "";
        vector<string> dir ;
        while(getline(ss, temp, '/'))
        {
            if(!temp.empty())
                dir.push_back(temp);

        }
        TrieNode* node = root;
        for(int i =0 ;i<dir.size();i++)
        {
            if(node->mp.count(dir[i])==0)
                return -1;
            
            node = node->mp[dir[i]];

            if(i==dir.size()-1)
            {
                
                return node->value;
            }
            
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