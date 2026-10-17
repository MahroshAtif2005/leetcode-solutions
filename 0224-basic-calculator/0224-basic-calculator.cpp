class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int sign = 1;
        long long num = 0;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
        
        else if (s[i] == '+') {
            total += sign * num;
            num = 0;
            sign = 1;
        }
        else if (s[i] == '-') {
            total += sign * num;
            num = 0;
            sign = -1;
        }

        if (s[i] == '(') {
            st.push(total);
            st.push(sign);

            total = 0;
            sign = 1;
        }
        if (s[i] == ')') {
            total += sign * num;
            num = 0;

            int prevSign = st.top();
            st.pop();

            int prevSum = st.top();
            st.pop();

            total = prevSum + prevSign * total;
        }
        }
    total += sign * num;
    return total;
}
}
;