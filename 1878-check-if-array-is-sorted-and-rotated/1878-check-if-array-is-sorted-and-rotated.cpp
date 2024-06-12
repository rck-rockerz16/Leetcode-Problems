class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size(), cnt = 0;
        if (nums[0] < nums[size - 1])
            cnt++;
        for (int i = 1; i < size; i++)
            if (nums[i] < nums[i - 1]) {
                cnt++;
                if (cnt > 1)
                    return false;
            }
        return true;
    }
};