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

//Recursive
class Solution {
public:

    void helperf(TreeNode* root , vector<int> & ans){
        if(root ==nullptr)
            return ;
        
        ans.push_back(root->val);
        helperf(root->left,ans);
        helperf(root->right,ans);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helperf(root, ans);
        return ans;

    }
};
//Iterative
