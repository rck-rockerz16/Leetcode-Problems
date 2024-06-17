class Solution {
private:
    int countNoOfOne(int index) {
        int cnt = 0;
        while (index > 0) {
            if (index & 1)
                cnt++;
            index = index >> 1;
        }
        return cnt;
    }

public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            ans[i] = ans[i>>1] + (i&1);
            // ans[i] = countNoOfOne(i);
        }
        return ans;
    }
};