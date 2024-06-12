class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int count = 0, maxi = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (nums[i])
                count++;
            else
                count = 0;
            maxi = max(count, maxi);
        }
        return maxi;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();