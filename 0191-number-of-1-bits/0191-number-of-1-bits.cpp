class Solution {
public:
    int hammingWeight(int n) {
        int rem,c=0;
        if (n == 0)
            return 0;
        else {
            while (n > 0) {
                int rem = n % 2;
                if(rem==1)
                    c++;
                n /= 2;
            }
        }
        return c;
    }
};