class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long> st;
        long long res = 0;
        for(int i=0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    res = (a+b);
                } else if(tokens[i] == "-"){
                    res = (a-b);
                } else if(tokens[i] == "*"){
                    res = (a*b);
                } else {
                    res = (a/b);
                }

                st.push(res);
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
    return st.top();
    }
};
