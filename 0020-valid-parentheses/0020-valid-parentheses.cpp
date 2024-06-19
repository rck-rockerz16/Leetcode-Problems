class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int size = s.size();
        
        if (size % 2 != 0) {
            return false; 
        }
        
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    stck.push(s[i]);
                    break;
                case ')':
                    if (stck.empty() || stck.top() != '(')
                        return false;
                    stck.pop();
                    break;
                case '}':
                    if (stck.empty() || stck.top() != '{')
                        return false;
                    stck.pop();
                    break;
                case ']':
                    if (stck.empty() || stck.top() != '[')
                        return false;
                    stck.pop();
                    break;
                default:
                    // If there's any other character, it's invalid
                    return false;
            }
        }
        
        return stck.empty(); 
    }
};
