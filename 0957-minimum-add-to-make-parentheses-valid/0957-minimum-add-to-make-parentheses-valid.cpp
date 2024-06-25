class Solution {
public:
    int minAddToMakeValid(string str) {
        int unmatchedOpen = 0;
        int unmatchedClose = 0;

        for (char c : str) {
            if (c == '(') {
                unmatchedOpen++;
            } else if (c == ')') {
                if (unmatchedOpen > 0) {
                    unmatchedOpen--;
                } else {
                    unmatchedClose++;
                }
            }
        }

        return unmatchedOpen + unmatchedClose;
    }
};
