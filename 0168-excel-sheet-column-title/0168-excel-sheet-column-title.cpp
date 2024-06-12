class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int n = columnNumber;
        while (n > 0) {
            n--;
            int rem = n % 26;
            ans = (char)(rem + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};