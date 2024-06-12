class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        int i, j;

        for (j = 0; j < s.length(); j++)
            if (s[j] != ' ')
                break;

        for (i = s.length() - 1; i >= 0; i--)
            if (s[i] != ' ')
                break;

        for (int k = i; k >= j; k--)
            if (s[k] != ' ')
                word = s[k] + word;
            else if (!word.empty()) {
                ans += word + " ";
                word = "";
            }
        if (!word.empty())
            ans += word;

        if (!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};