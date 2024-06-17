class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (i <= s.size()) {
            if (s[i] == ' ' || s[i] == '\0') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
            i++;
        }
        return s;

        // Alternate Soln
        // string ans, word;
        // for (auto chr : s) {
        //     if (chr == ' ') {
        //         ans += word + " ", word = "";
        //         continue;
        //     }
        //     word = chr + word;
        // }
        // ans += word;
        // return ans;
    }
};