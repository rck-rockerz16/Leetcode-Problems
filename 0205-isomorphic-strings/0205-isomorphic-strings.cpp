class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        map<char, char> mpS,mpT;
        for (int i = 0; i < s.length(); i++)
            if ((mpS.count(s[i]) || mpT.count(t[i])) &&
                (mpS[s[i]] != t[i] || mpT[t[i]] != s[i]))
                return false;
            else
            {
                mpS[s[i]]=t[i];
                mpT[t[i]]=s[i];
            }
        return true;
    }
};