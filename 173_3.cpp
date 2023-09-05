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
    TreeNode* cur = nullptr;

public:
    BSTIterator(TreeNode* root) {
        cur =root;
    }
    
    int next() {
        
        int val =0;
    while(cur!=nullptr)
    {
        if(cur->left==nullptr)
        {
            val = cur->val;
            cur = cur->right;
            return val;
        }
        else 
        {
            TreeNode* temp = cur->left;
            while(temp->right!=nullptr && temp->right!=cur)
            {
                temp = temp->right;
            }

            if(temp->right ==nullptr)
            {
                // not visited left substree yet
                temp->right =cur;
                cur = cur->left;
            }
            else 
            {
                temp->right = nullptr;
                val = cur->val;
                cur = cur->right;
                return val;

            }
        }

    }
        return val;
        
    }
    
    bool hasNext() {
        return cur!=nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */