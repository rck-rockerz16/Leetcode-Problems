class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (!size)
            return "";

        sort(strs.begin(), strs.end());

        string prefix = strs[0];
        int prefixLength = prefix.length();

        for (int i = 1; i < size; i++) {
            while (prefix != strs[i].substr(0, prefixLength)) {
                prefixLength--;
                if (!prefixLength)
                    return "";
                prefix = prefix.substr(0, prefixLength);
            }
        }
        return prefix;
    }
};