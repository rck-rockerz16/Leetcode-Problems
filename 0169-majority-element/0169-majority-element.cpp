class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;

        for (auto i : mp)
            if (i.second > nums.size() / 2)
                return i.first;

        return -1;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();