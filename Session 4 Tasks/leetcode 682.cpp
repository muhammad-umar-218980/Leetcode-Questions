class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0 ; i < operations.size();i++){
            string op = operations[i];
            if(op == "+"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.push(b);
                st.push(a+b);
            }else if(op == "C"){
                st.pop();
            }else if(op == "D"){
                st.push(2*st.top());
            }else{
                st.push(stoi(op));
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum+= st.top();
            st.pop();
        }

        return sum;
    }

};