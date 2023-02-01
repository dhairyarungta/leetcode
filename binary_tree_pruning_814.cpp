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
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(root->left == nullptr && root->right == nullptr && root->val ==0)return nullptr;
        
        return root;
            }
};

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
class Solution {
public:

    bool recurPruneTree(TreeNode* root){
        if(root == nullptr)
            return false;

        bool rightSubT = recurPruneTree(root->right);
        bool leftSubT = recurPruneTree(root->left);
        bool rootVal = rightSubT | leftSubT;
        if (leftSubT==false )
            root->left = nullptr;
        if(rightSubT==false)
            root->right = nullptr;

        return rootVal|root->val;

}
    TreeNode* pruneTree(TreeNode* root) {        
        recurPruneTree(root);
        
        if(root->val ==0 && root->left ==nullptr && root->right ==nullptr){
            return nullptr;
        }
        
        return root; 
    }
};
