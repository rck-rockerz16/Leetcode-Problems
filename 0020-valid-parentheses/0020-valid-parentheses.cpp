class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int size = s.size();
        if (size == 1 || size == 0) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' || stck.empty())
                stck.push(s[i]);
            else if (s[i] == ')' && stck.top() == '(')
                stck.pop();
            else if (s[i] == '}' && stck.top() == '{')
                stck.pop();
            else if (s[i] == ']' && stck.top() == '[')
                stck.pop();
            else
                stck.push(s[i]);
        }
        if (stck.empty())
            return true;
        return false;
    }
};