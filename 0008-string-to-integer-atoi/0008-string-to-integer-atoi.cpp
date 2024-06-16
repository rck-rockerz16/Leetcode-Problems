class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long num = 0;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                if (num > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (num > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;
            } else
                return sign * num;
        }
        return sign * num;
    }
};