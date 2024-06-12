class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        long n, digit = 0;
        n = x;
        while (n > 0) {
            digit = digit * 10 + (n % 10);
            n = n / 10;
        }
        return digit==x?true:false;
    }
};