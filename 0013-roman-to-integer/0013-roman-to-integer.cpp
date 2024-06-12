class Solution {
public:
    int romanToInt(string s) {
        int sum = 0, size;
        size = s.size();
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
            case 'I':
                if (s[i + 1] == 'V') {
                    sum = sum + 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    sum = sum + 9;
                    i++;
                } else
                    sum = sum + 1;
                break;
            case 'V':
                sum = sum + 5;
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    sum = sum + 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    sum = sum + 90;
                    i++;
                } else
                    sum = sum + 10;
                break;
            case 'L':
                sum = sum + 50;
                break;
            
            case 'C':
                if (s[i + 1] == 'D') {
                    sum = sum + 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    sum = sum + 900;
                    i++;
                } else
                    sum = sum + 100;
                break;
            case 'D':
                sum = sum + 500;
                break;
            case 'M':
                sum = sum + 1000;
                break;
            }
        }
        return sum;
    }
};