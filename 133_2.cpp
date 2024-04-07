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
        if(node ==nullptr)
            return node;
        queue<Node*>q;
        unordered_map<Node*,Node*>mp;
        q.push(node);
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            Node *newNode = nullptr;
            if(mp.contains(curNode)){
                newNode = mp[curNode];
            }
            else {
                newNode= new Node(curNode->val);
                mp[curNode] = newNode;
            }
            for(Node* neighNode: curNode->neighbors) {
                if(!mp.contains(neighNode)&& neighNode!=nullptr){

                    q.push(neighNode);
                    mp[neighNode] = new Node (neighNode->val);
                }
                (newNode->neighbors).push_back(mp[neighNode]);
            }         
        }
        return mp[node];
    }
};


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
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
       
    if(node==nullptr)
        return nullptr;
    if(!mp.contains(node)){
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
    }
    else {
        return mp[node];
    }
    for(Node* neighNode : node->neighbors){
        Node* tempNode = cloneGraph(neighNode);
        (mp[node]->neighbors).push_back(tempNode);
    }
    return mp[node];

    }
};
