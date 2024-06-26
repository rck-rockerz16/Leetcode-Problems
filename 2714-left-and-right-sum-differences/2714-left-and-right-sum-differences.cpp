class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer;
        int leftSum = 0, rightSum = 0;
        for (auto item : nums)
            rightSum += item;

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            answer.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }
        return answer;

        /*
        int n = nums.size();

        if (n == 0)
            return vector<int>{};
        if (n == 1)
            return vector<int>{0};

        vector<int> leftSum(n, 0), rightSum(n, 0), answer(n, 0);

        int i = 1, j = n - 2;
        while (i < n && j >= 0) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[j] = rightSum[j + 1] + nums[j + 1];
            i++, j--;
        }

        for (int k = 0; k < n; k++) {
            int diff = leftSum[k] - rightSum[k];
            answer[k] = (diff < 0) ? (-1 * diff) : diff;
            // answer[i]=abs(leftSum[i]-rightSum[i]);
        }
        return answer;
        */
    }
};