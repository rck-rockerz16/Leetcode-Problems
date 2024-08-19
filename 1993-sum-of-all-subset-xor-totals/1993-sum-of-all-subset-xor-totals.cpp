class Solution {
private:
    void calculateSubsetXOR(int& totalXOR, int currentXOR,
                            const vector<int> nums, int index, int size) {
        if (index > size - 1) {
            totalXOR += currentXOR;
            return;
        }
        // Recursive call without including the current element
        calculateSubsetXOR(totalXOR, currentXOR, nums, index + 1, size);

        // XOR with the current element and recurse
        currentXOR ^= nums[index];
        calculateSubsetXOR(totalXOR, currentXOR, nums, index + 1, size);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int totalXOR = 0;
        calculateSubsetXOR(totalXOR, 0, nums, 0, nums.size());
        return totalXOR;
    }
};
