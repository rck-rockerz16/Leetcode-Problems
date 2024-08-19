class Solution {
public:
    int percentageLetter(string s, char letter) {
        int freq = count(s.begin(), s.end(), letter);
        return (freq * 100) / s.length();
    }
};