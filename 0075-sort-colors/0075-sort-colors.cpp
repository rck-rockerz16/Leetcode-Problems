class Solution {
public:
    void sortColors(vector<int>& nums) {
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
    }
};