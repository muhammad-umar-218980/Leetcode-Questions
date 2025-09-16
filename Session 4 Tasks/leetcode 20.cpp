class Solution {
public:
    bool isValid(string s) {
        stack<char> stringStack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stringStack.push(s[i]);
            } else {
                if (stringStack.empty()) {
                    return false;
                }
                if ((s[i] == ')' && stringStack.top() != '(') ||
                    (s[i] == '}' && stringStack.top() != '{') ||
                    (s[i] == ']' && stringStack.top() != '[')) {
                    return false;
                }
                stringStack.pop();
            }
        }
        return stringStack.empty();
    }
};
