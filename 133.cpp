
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
        {
            cout<<"hello\n";
            return nullptr;
        }
            
        Node* baseNode = new Node(1);
        set<int>seen;
        stack<Node*>st;
        unordered_map<int,Node*>mp;
        st.push(node);
        unordered_map<int,set<int>>neigh;
       
        while(!st.empty()){
            Node* curNode = st.top();
            Node* newNode = nullptr;
            if(!mp.contains(curNode->val)){

                newNode = new Node(curNode->val);
                mp[curNode->val] = newNode;
            }
            else 
                newNode = mp[curNode->val];

            st.pop();
            seen.insert(curNode->val);
            for(Node* node : curNode->neighbors){
                if(!seen.contains(node->val)){
                    st.push(node);
                }
                if(!mp.contains(node->val)){
                    Node* tempNodeInsert = new Node(node->val);
                    mp[node->val] = tempNodeInsert;
                  //  (tempNodeInsert->neighbors).push_back(newNode);
                }
                vector<Node*>& ref= newNode->neighbors;
                //if(std::find(ref.begin(),ref.end(),mp[node->val])==ref.end())
                if(!neigh[newNode->val].contains(node->val)){

                    (newNode->neighbors).push_back(mp[node->val]);
                    neigh[newNode->val].insert(node->val);
                }
            }
        }
//        for(auto [i,node]: mp){
//           cout<<i<<" "<<node->val<<'\n';
//           for(auto neighbor : node->neighbors){
//            cout<<neighbor->val<<" ";
//           }
//           cout<<'\n'; 
//        }
        return mp[1];

    }
};
