class Node{
public: 
    bool isDir = true;
    map<string,Node>dir;
    string fil;
};

class FileSystem {

    Node root; 
public:
    ~FileSystem(){
        for(auto [i,j] : root.dir){
        }
    }
    FileSystem() {
        Node root;
        root.isDir = true;
    }
    
    vector<string> ls(string path) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        Node *temp = &root;
        vector<string>v;
        if(path=="/"){
            for(auto [i,j]:root.dir)
                v.push_back(i);
            return v;
        }
        else {
            std::stringstream ss(path.substr(1));
            string token;
            while(getline(ss, token, '/')){
                v.push_back(token);
            }
        }
        vector<string>returnVec;
        for (int i = 0;i<v.size();i++){
            temp = &(temp->dir[v[i]]);
        }
        if(temp->isDir){
            for(auto [i,j]:temp->dir){
                returnVec.push_back(i);
            }
            return returnVec;
        }
        else {
            return vector<string>{path.substr(path.find_last_of('/')+1)};
        }
        


    }
    
    void mkdir(string path) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        stringstream ss(path.substr(1));
        string token;
        vector<string>v;
        
        while(getline(ss, token, '/')){
            v.push_back(token);
            // cout<<token<<endl;
        }
        Node *temp = &root;
        for(size_t i = 0;i<v.size();i++){
            if(temp->dir.contains(v[i])){
                // cout<<"1"<<" ";
                temp = &(temp->dir[v[i]]);
            }
            else {
                // cout<<"2"<<" ";
                (temp->dir[v[i]]) = Node();
                (temp->dir[v[i]]).isDir = true;
                temp = &(temp->dir[v[i]]);
            }
        }
        // cout<<endl;
    }
    
    void addContentToFile(string filePath, string content) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        stringstream ss(filePath.substr(1));
        string token;
        vector<string>v;
        while(getline(ss,token,'/')){
           v.push_back(token); 
        }
        Node *temp = &root;
        for(size_t i = 0;i<v.size();i++){

            if(temp->dir.contains(v[i])){
                temp = &(temp->dir[v[i]]);
            }
            else{
                temp->dir[v[i]] = Node();
                (temp->dir[v[i]]).isDir = true;
                temp = &(temp->dir[v[i]]);

            }
        }
        
        if(temp->isDir==true){
            temp->isDir = false;
            temp->fil = content;
        }
        else {
            temp->fil.append(content);
        }


    }
    
    string readContentFromFile(string filePath) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        stringstream ss(filePath.substr(1));
        string token;
        vector<string>v;
        while(getline(ss,token,'/')){
           v.push_back(token) ;
        }
        Node* temp = &root;
        for(int i = 0;i<v.size();i++){
            temp = &(temp->dir[v[i]]);
        }
        if(temp->isDir==false){
            return temp->fil;
        }
        else{
            return "";
        }

    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
