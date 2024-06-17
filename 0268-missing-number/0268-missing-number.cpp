class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumWhole = (n * (n + 1)) / 2, sumNums = 0;
        for (int i=0;i<n;i++)
            sumNums += nums[i];
        return sumWhole - sumNums;
    }
};