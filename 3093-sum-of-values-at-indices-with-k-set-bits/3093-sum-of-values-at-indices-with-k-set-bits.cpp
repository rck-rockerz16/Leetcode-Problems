class Solution {
private:
    bool hasKSetBits(int index, int k) {
        int cnt = 0;
        while (index > 0) {
            if (index & 1)
                cnt++;

            index = index >> 1;
        }
        return cnt == k;
        /*
        bitset<32> bs(index); 
        string binaryString = bs.to_string(); 
        
        int cnt = 0;
        for (char bit : binaryString) {
            if (bit == '1') {
                cnt++;
            }
        }
        return cnt == k;
        */
    }

public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (hasKSetBits(i, k))
                sum += nums[i];
        }
        return sum;
    }
};