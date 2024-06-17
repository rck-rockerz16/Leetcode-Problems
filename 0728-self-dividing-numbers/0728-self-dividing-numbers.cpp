class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            string str = to_string(i);
            bool selfDividing = true;
            for (auto digit : str) {
                if (digit == '0' || i % (digit - '0') != 0) {
                    selfDividing = false;
                    break;
                }
            }
            if (selfDividing)
                ans.push_back(i);
        }
        return ans;
    }
};
