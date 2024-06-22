class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stackOperations;
        vector<int> stack;

        for (int i = 1, j = 0; i <= n; i++) {
            if (stack == target)
                return stackOperations;

            stackOperations.push_back("Push");

            if (i == target[j]) {
                stack.push_back(i);
                j++;
            } else
                stackOperations.push_back("Pop");
        }
        return stackOperations;
    }
};