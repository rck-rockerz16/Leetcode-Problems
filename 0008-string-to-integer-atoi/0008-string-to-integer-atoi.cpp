class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long num = 0;

        if (isalpha(s[0]))
            return num;
            
        while (i < s.length() && s[i] == ' ')
            i++;

        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (num > (INT_MAX - digit) / 10)
                return (sign == -1) ? INT_MIN : INT_MAX;

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};