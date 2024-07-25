/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& inorder_nodes) {
        if (!root)
            return;
        inorder(root->left, inorder_nodes);
        inorder_nodes.push_back(root->val);
        inorder(root->right, inorder_nodes);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> ans;
        TreeNode* curr = root;
        while (curr || !nodes.empty()) {
            while (curr) {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
        /*
            vector<int> inorder_nodes;
            inorder(root, inorder_nodes);
            return inorder_nodes;
        */
    }
};
