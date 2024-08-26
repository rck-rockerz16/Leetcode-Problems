class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroBoundary = 0, current = 0, twoBoundary = nums.size() - 1;
        while (current <= twoBoundary) {
            if (nums[current] == 0) {
                swap(nums[zeroBoundary], nums[current]);
                zeroBoundary++, current++;
            } else if (nums[current] == 1) {
                current++;
            } else {
                swap(nums[current], nums[twoBoundary]);
                twoBoundary--;
            }
        }
    }
};
/*
int size = nums.size();
int red = 0, white = 0;
for (int i : nums) {
    if (!i)
        red++;
    else if (i == 1)
        white++;
}
for (int itr = 0; itr < size; itr++) {
    if (itr < red)
        nums[itr] = 0;
    else if (itr >= red && itr < (red + white))
        nums[itr] = 1;
    else
        nums[itr] = 2;
}
*/