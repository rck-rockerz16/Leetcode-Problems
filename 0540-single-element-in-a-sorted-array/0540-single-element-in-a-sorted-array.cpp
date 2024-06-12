class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (nums.size() == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (*nums.rbegin() != *(nums.rbegin() + 1))
            return *nums.rbegin();

        int low = 1, high = nums.size() - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            else if (mid % 2 == 0)
                if (nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            else if (nums[mid] == nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};