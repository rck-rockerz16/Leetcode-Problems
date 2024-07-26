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
    /*
    private:
        void preorder(TreeNode* curr, vector<int>& preorder_nodes) {
            if (!curr)
                return;
            preorder_nodes.push_back(curr->val);
            preorder(curr->left, preorder_nodes);
            preorder(curr->right, preorder_nodes);
        }
    */

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodes;
        TreeNode* curr = root;

        while (curr != nullptr || !nodes.empty()) {
            if (curr != nullptr) {
                ans.push_back(curr->val);
                nodes.push(curr->right);
                curr = curr->left;
            } else {
                curr = nodes.top();
                nodes.pop();
            }
        }

        return ans;
    }
};
/*
vector<int> preorder_nodes;
preorder(curr, preorder_nodes);
return preorder_nodes;
*/