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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        stack<TreeNode*> st;

        while(root!=nullptr || !st.empty())
        {
            while(root!=nullptr)
            {
                st.push(root);
                root= root->left;
            }
            root=st.top();
            st.pop();
            vec.push_back(root->val);
            root=root->right;

        }
    
    return vec[k-1];
    }



};