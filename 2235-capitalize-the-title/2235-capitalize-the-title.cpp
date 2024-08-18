class Solution {
public:
    string capitalizeTitle(string title) {
        string word = "", ans = "";
        bool firstChar = true;
        title.push_back(' ');

        for (auto chr : title)
            if (chr == ' ') {
                if (word.length() <= 2)
                    word[0] = tolower(word[0]);
                ans += word + ' ';
                word = "", firstChar = true;
            } else {
                chr = firstChar ? toupper(chr) : tolower(chr);
                firstChar = false, word += chr;
            }
        
        ans.pop_back();
        return ans;
    }
};