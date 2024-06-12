class Solution {
public:
    int mySqrt(int x) {
        if (!x || x == 1)
            return x;

        long start = 1, end = x, ans = 0;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long square = mid * mid;

            if (square == x)
                return mid;
            else if (square < x) {
                ans = mid;
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return ans;
    }
};