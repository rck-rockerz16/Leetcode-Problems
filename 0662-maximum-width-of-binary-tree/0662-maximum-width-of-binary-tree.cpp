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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        long max_width = 0;
        queue<pair<TreeNode*, long>> nodeQueue;
        nodeQueue.push({root, 0});
        while (!nodeQueue.empty()) {
            long levelSize = nodeQueue.size();
            long firstIndex = nodeQueue.front().second;
            long lastIndex = nodeQueue.back().second;
            max_width = max(max_width, lastIndex - firstIndex + 1);
            for (int i = 0; i < levelSize; i++) {
                pair<TreeNode*, int> curr = nodeQueue.front();
                nodeQueue.pop();
                if (curr.first->left)
                    nodeQueue.push(
                        {curr.first->left, (long)2 * curr.second + 1});
                if (curr.first->right)
                    nodeQueue.push(
                        {curr.first->right, (long)2 * curr.second + 2});
            }
        }
        return max_width;
    }
};