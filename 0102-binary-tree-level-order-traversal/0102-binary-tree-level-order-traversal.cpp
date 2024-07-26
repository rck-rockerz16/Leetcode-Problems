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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int levelSize = nodes.size(); 
            vector<int> lvlnodes;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();
                lvlnodes.push_back(curr->val);

                if (curr->left != nullptr)
                    nodes.push(curr->left);
                if (curr->right != nullptr)
                    nodes.push(curr->right);
            }

            ans.push_back(lvlnodes); 
        }

        return ans;
    }
};