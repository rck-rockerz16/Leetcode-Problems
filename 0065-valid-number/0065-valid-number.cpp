class Solution {
private:
    bool isSign(char ch) { return (ch == '+' || ch == '-'); }

public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.size();

        if (isSign(s[i]))
            i++;

        bool isNumeric = false;

        while (isdigit(s[i]))
            i++, isNumeric = true;

        if (s[i] == '.') {
            i++;
            while (isdigit(s[i]))
                i++, isNumeric = true;
        }

        if (isNumeric && (tolower(s[i]) == 'e')) {
            i++, isNumeric = false;

            if (isSign(s[i]))
                i++;

            while (isdigit(s[i]))
                i++, isNumeric = true;
        }

        return isNumeric && i == n;
    }
};