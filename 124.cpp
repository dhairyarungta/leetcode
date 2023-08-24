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
    
    int maxPathSum(TreeNode* root) {
        int val= INT_MIN;
        helperf(root, val);
        return val;
    }

    int helperf(TreeNode* root, int & val)
    {
        if(root==nullptr) return 0;
        int lvalue = helperf(root->left, val);
        int rvalue = helperf(root->right, val);
        int l = lvalue<0?0:lvalue;
        int r = rvalue<0?0:rvalue;
        val = max(val, root->val+l+r);
        return max(l+root->val, r+root->val);
    }
};