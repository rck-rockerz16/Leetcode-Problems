class Solution {
public:
    bool isVowel(char ch) {
        ch = toupper(ch);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0, j = n / 2; i < n / 2 & j < n; i++, j++) {
            if (isVowel(s[i]))
                cnt++;
            if (isVowel(s[j]))
                cnt--;
        }

        return cnt == 0 ? true : false;
    }
};