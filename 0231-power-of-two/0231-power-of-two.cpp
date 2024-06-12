class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        double value = log2(n);
        return (pow(2 ,value) == n) && round(value)==value;
    }          
};