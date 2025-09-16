class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(tokens[i] == "+") {
                    st.push(a + b);
                } else if(tokens[i] == "-") {
                    st.push(a - b);
                } else if(tokens[i] == "*") {
                    st.push(a * b);
                } else {
                    if(b != 0) {
                        st.push(a / b);
                    } else {
                        return 0; 
                    }
                }
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
