class Solution {
public:
    int getPivot(vector<int>& nums, int size) {
        int low = 0, high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= nums[0])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    int binarySearch(vector<int>& nums, int size, int target, int l, int h) {
        int low = l, high = h;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int pivot = getPivot(nums, size);
        if (target >= nums[pivot] && target <= nums[size - 1])
           return binarySearch(nums, size, target, pivot, size - 1);
        else
            return binarySearch(nums, size, target, 0, pivot - 1);
    }
};