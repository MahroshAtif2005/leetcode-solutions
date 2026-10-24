class Solution {
public:
    int calculate(string s) {
      int total = 0;
      stack<int> st;
      char operation = '+';
      int num = 0;

      for(int i = 0; i<s.size(); i++){
        if(isdigit(s[i])){
            num = num * 10 + (s[i]-'0');
        }

        if((!isdigit(s[i]) && s[i] != ' ')|| i==s.size()-1){
            if(operation=='+'){
                st.push(num);
            }
            if(operation == '-'){
                st.push(-num);
            }
            if(operation == '*'){
                int prev = st.top();
                st.pop();
                st.push(prev*num);
            }
            if(operation == '/'){
                int prev = st.top();
                st.pop();
                st.push(prev/num);
            }
            operation = s[i];
            num = 0;
        }
      }
      while(!st.empty()){
        total += st.top();
        st.pop();
      }
      return total;
    }
};