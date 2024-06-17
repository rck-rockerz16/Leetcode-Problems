class Solution {
public:
    bool isAnagram(string s, string t) {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);

        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                return false;
            }
        }
        
        return true;
        // map<char, int> mpS;
        // for (auto chr1 : s)
        //     mpS[chr1]++;

        // map<char, int> mpT;
        // for (auto chr2 : t)
        //     mpT[chr2]++;

        // for (auto ch : mpT)
        //     if (!mpS.count(ch.first) || mpS[ch.first] != mpT[ch.first])
        //         return false;

        // return true;
    }
};