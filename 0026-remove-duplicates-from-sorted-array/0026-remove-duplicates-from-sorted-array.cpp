class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int inplace = 0;
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[inplace])
                continue;
            else {
                nums[inplace + 1] = nums[i];
                inplace++;
            }
        }
        return inplace + 1;
    }
};