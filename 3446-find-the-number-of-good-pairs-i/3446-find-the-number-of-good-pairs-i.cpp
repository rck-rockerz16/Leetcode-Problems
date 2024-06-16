class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        for (auto i : nums1) 
            for (auto j : nums2) {
                int div = j * k;
                if (i % div == 0)
                    cnt++;
            }
        return cnt;
    }
};