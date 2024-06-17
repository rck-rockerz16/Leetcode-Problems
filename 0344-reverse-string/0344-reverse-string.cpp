class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        if (n == 1)
            return;
        if (n == 2) {
            swap(s[0], s[1]);
            return;
        }
        
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);
    }
};