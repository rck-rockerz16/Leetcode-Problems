class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return vector<int>{};
        int size = nums.size();
        vector<int> ans;
        int *arr = (int*)calloc(size, sizeof(int));
        for (int i = 0; i < size; i++)
            arr[nums[i] - 1]++;

        for (int i = 0; i < size; i++)
            if (arr[i] == 2)
                ans.push_back(i+1);
        return ans;
    }
};