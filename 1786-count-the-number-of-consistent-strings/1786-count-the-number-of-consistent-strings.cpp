class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int cnt = 0;
        
        for (const auto& word : words) {
            bool consistent = true;

            for (const auto& ch : word) 
                if (allowedSet.find(ch) == allowedSet.end()) {
                    consistent = false;
                    break;
                }
            
            if (consistent) 
                cnt++;
        }
        
        return cnt;
    }
};