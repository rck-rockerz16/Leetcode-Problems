class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (auto chr : s)
            if (chr == '*')
                ans.pop_back();
            else
                ans.push_back(chr);

        return ans;
    }
};