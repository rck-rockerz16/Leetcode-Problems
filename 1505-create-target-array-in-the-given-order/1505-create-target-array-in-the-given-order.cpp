class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        if (n == 1)
            return vector<int>{nums[0]};

        vector<int> target;
        for (int i = 0; i < n; i++)
            if (index[i] >= target.size())
                target.push_back(nums[i]);
            else
                target.insert(target.begin() + index[i], nums[i]);

        return target;
    }
};