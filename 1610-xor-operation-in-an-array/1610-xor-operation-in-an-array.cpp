class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = start + 2 * i;
            sum ^= nums[i];
        }
        return sum;
    }
};