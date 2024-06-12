const int ZERO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer;
        int size = boxes.length();

        for (int i = 0; i < size; i++) {
            int dist = 0;
            for (int j = 0; j < size; j++) {
                if (boxes[j] == '1') {
                    dist += abs(j - i);
                }
            }
            answer.push_back(dist);
        }
        return answer;
    }
};
