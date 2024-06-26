class Solution {
public:
    int charToDigit(char ch) {
        switch (ch) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
        }
    }
    string largestOddNumber(string num) {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        int len = num.length() - 1;
        for (int i = len; i >= 0; --i)
            if (charToDigit(num[i]) % 2 != 0)
                return num.substr(0, i + 1);

        return "";
    }
};