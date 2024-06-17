class Solution {
private:
    bool hasKSetBits(int index, int k) {
        int cnt = 0;
        while (index > 0) {
            if (index & 1)
                cnt++;

            index = index >> 1;
        }
        return cnt == k;
    }

public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (hasKSetBits(i, k))
                sum += nums[i];
        }
        return sum;
    }
};