class Solution {
private:
    void find_parents(TreeNode* root,
                      unordered_map<TreeNode*, TreeNode*>& childToParent) {
        if (!root)
            return;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* curr = nodeQueue.front();
            nodeQueue.pop();
            if (curr->left) {
                nodeQueue.push(curr->left);
                childToParent[curr->left] = curr;
            }
            if (curr->right) {
                nodeQueue.push(curr->right);
                childToParent[curr->right] = curr;
            }
        }
    }
    void
    find_nodes_distanceK(TreeNode* root, TreeNode* target, int k,
                         queue<TreeNode*>& nodeQueue,
                         unordered_map<TreeNode*, TreeNode*>& childToParent) {

        unordered_map<TreeNode*, bool> visitedNode;
        nodeQueue.push(target);
        visitedNode[target] = true;
        int curr_dist = 0;
        while (!nodeQueue.empty()) {
            if (curr_dist == k)
                break;
            curr_dist++;

            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();

                if (curr->left && !visitedNode[curr->left]) {
                    nodeQueue.push(curr->left);
                    visitedNode[curr->left] = true;
                }

                if (curr->right && !visitedNode[curr->right]) {
                    nodeQueue.push(curr->right);
                    visitedNode[curr->right] = true;
                }

                TreeNode* parentNode = childToParent[curr];
                if (parentNode && !visitedNode[parentNode]) {
                    nodeQueue.push(parentNode);
                    visitedNode[parentNode] = true;
                }
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> childToParent;
        find_parents(root, childToParent);

        queue<TreeNode*> nodeQueue;
        find_nodes_distanceK(root, target, k, nodeQueue, childToParent);

        vector<int> ans;
        while (!nodeQueue.empty()) {
            ans.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
        }
        return ans;
    }
};