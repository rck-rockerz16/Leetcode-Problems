class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long num = 0;

        if (s[i] >= 'a' && s[i] <= 'Z')
            return num;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {

            num = num * 10 + s[i] - '0';

            if (num > INT_MAX)
                return (sign == -1) ? INT_MIN : INT_MAX;

            i++;
        }

        return sign * num;
    }
};