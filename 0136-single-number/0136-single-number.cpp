class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int, int> mp;

        // if (nums.size() == 1)
        //     return nums[0];

        // for (int i : nums)
        //     mp[i]++;

        // for (auto i : mp)
        //     if (i.second == 1)
        //         return i.first;
        // return 0;
        int item = 0;
        for (auto i : nums)
            item = item ^ i;
        return item;
    }
};