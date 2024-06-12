class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int curr = pref[0];
        vector<int> result(pref.size());
        result[0] = pref[0];
        for (int i = 1; i < pref.size(); i++)
            result[i] = curr ^ pref[i], curr = pref[i];
        return result;
    }
};