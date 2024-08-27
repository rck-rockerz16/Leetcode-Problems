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
                childToParent[curr->left] = curr;
                nodeQueue.push(curr->left);
            }

            if (curr->right) {
                childToParent[curr->right] = curr;
                nodeQueue.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0)
            return {target->val};

        unordered_map<TreeNode*, TreeNode*> childToParent;
        find_parents(root, childToParent);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(target), visited.insert(target);

        int curr_dist = 0;

        while (!nodeQueue.empty()) {
            if (curr_dist == k)
                break;
            curr_dist++;

            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();

                if (curr->left && visited.find(curr->left) == visited.end())
                    nodeQueue.push(curr->left), visited.insert(curr->left);

                if (curr->right && visited.find(curr->right) == visited.end())
                    nodeQueue.push(curr->right), visited.insert(curr->right);

                TreeNode* parent = childToParent[curr];
                if (parent && visited.find(parent) == visited.end())
                    nodeQueue.push(parent), visited.insert(parent);
            }
        }

        vector<int> result;
        while (!nodeQueue.empty()) {
            result.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
        }

        return result;
    }
};
