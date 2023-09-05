/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    TreeNode* root;
    TreeNode* cur = nullptr;
public:
    BSTIterator(TreeNode* root): root(root) {
        cur = root;
    }
    
    int next() {
        while(cur!=nullptr)
        {   
            s.push(cur);
            cur=cur->left;
        }
        int ansVal = s.top()->val;
        cur = s.top()->right;
        s.pop();

        return ansVal;
        
    }
    
    bool hasNext() {
         if(cur==nullptr && s.empty())
            return false;
        else
            return true;

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */