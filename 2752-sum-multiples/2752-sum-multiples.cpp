class Solution {
private:
    int sumDivisibleByk(int k, int n) {
        int p = n / k;
        return k * ((p * (p + 1)) / 2);
    }

public:
    int sumOfMultiples(int n) {
        int sum_3 = sumDivisibleByk(3, n);
        int sum_5 = sumDivisibleByk(5, n);
        int sum_7 = sumDivisibleByk(7, n);

        int sum_15 = sumDivisibleByk(15, n);
        int sum_21 = sumDivisibleByk(21, n);
        int sum_35 = sumDivisibleByk(35, n);
        int sum_105 = sumDivisibleByk(105, n);

        return ((sum_3 + sum_5 + sum_7) - (sum_15 + sum_21 + sum_35) + sum_105);
    }
};