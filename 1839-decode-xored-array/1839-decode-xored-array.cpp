class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int sizeOfEncoded = encoded.size();
        vector<int> arr(sizeOfEncoded + 1);
        
        arr[0] = first;
        for (int i = 0; i < sizeOfEncoded; i++)
            arr[i + 1] = encoded[i] ^ arr[i];

        return arr;
    }
};