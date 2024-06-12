class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rear = digits.size() - 1;
        while (rear >= 0) {
            if (digits[rear] == 9) {
                digits[rear] = 0;
                rear--;
            } else {
                digits[rear]++;
                return digits;
            }
        }
        if (rear == -1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};