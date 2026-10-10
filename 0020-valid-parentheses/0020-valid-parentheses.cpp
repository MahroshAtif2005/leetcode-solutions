class Solution {
public:
    bool isValid(string s) {
      //stack
      //if it is a opeing bracket, put it in the stack
      //if it is a closing bracking take it out, if it matches teh last bracket its true, otherwise its false
      stack<char> st;

     for (int i = 0; i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }else if(s[i]==')'){
            if (st.empty()) return false;
            char bracket = st.top();
            if(bracket != '('){
                return false;
            }
            st.pop();
        }else if(s[i]=='}'){
            if (st.empty()) return false;
           char bracket = st.top();
            if(bracket != '{'){
                return false;
            }
            st.pop();
        }else if(s[i]==']'){
            if (st.empty()) return false;
           char bracket = st.top();
            if(bracket != '['){
                return false;
            }
            st.pop();
      }
    }
    return st.empty();
    }
};