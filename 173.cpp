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
    TreeNode* root;
    TreeNode* cur;
    queue<int>q;

    void inOrderTraversal(TreeNode* base)
    {
        stack<TreeNode*> s;
        TreeNode* temp = base;
        while(base!= nullptr || s.size()!=0)
        {

            while(base!=nullptr)
            {
                s.push(base);
                base = base->left;
            }
            q.push(s.top()->val);
            base = s.top()->right;
            s.pop();

        }
        // while(q.size()!=0)
        // {
        //     cout<<q.front()<<" ";
        //     q.pop();
        // }
        

    }

public:
    BSTIterator(TreeNode* root):root(root) {
        inOrderTraversal(root);
    }
    
    int next() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return q.empty()?false:true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */