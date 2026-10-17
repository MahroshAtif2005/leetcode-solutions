class Solution {
public:
    int calculate(string s) {
        int total = 0;
        stack<int> st;
        char operation = '+'; //operation is keepin track 
        int num = 0;

        for (int i = 0; i < s.size(); i++) {

            // Process each character
            // set num = 0 at some point
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // process when we encounter a operator or reach the end
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {

                if (operation == '+') {
                    st.push(num);
                }
                else if (operation == '-') {
                    st.push(-num);
                }

                else if (operation == '*') {
                    int previous = st.top();
                    st.pop();
                    st.push(previous * num);
                }
                   else if (operation == '/') {
                    int previous = st.top();
                    st.pop();
                    st.push(previous / num);
                }
                operation = s[i];
                num = 0;
            }
        }
        while(!st.empty()){
            total+=st.top();
            st.pop();
        }
        return total;
    }
};