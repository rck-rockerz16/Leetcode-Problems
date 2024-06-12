class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> mp;
        for (int i = 0; i < size; i++)
            mp[nums[i]] = i;

        for (int i = 0; i < size; i++) {
            int comp = target - nums[i];
            if (mp.count(comp) && mp[comp] != i)
                return {i, mp[comp]};
        }
        return vector<int>{-1,-1};
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();