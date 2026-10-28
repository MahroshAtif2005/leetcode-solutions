class Solution {
public:
    string minRemoveToMakeValid(string s) {
    //saved space by putting '#' in place rather than putting a set
      stack<int> st;

      for(int i = 0; i<s.size(); i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){
           if(st.empty()){
             s[i]='#';
           }else{
              st.pop();
           }
        }else {
            continue;
        }
      }

      while(!st.empty()){
        s[st.top()]='#';
        st.pop();
      }
      
      string answer;
      for(int i = 0; i<s.size() ; i++){
        if(s[i]!='#'){
           answer += s[i];
        }
      }
      return answer;
    }
};