/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
        {
            return "#";
        }
        return string(to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream out(data) ;
        return deserializeHelper(out);
    }

private :
    TreeNode* deserializeHelper(stringstream& out){
        string temp;
        out>>temp;
        if(temp=="#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = deserializeHelper(out);
        root->right = deserializeHelper(out);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));