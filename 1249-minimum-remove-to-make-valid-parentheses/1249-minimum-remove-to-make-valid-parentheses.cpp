class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //go through the string
        //if see a bracket add index in the stack, if closed put it out, at the end if any ndices left in the stack, build the final string but without it
        stack<int> st;
        for (int i = 0; i<s.size(); i++){
            if(s[i]=='('){
              st.push(i);
            }else if(s[i]==')'){
                if(!st.empty()){
                st.pop();
                }else {//unmatched closing parenthesis for removal later
                  s[i] = '#';
                  }
            }else{
                continue;
            }
        }
     
        while(!st.empty()){
          s[st.top()] = '#';
          st.pop();
        }
        
        string answer="";

        for (int i = 0; i<s.size(); i++){
            if(s[i]!='#'){
                answer+=s[i];
            }
        }
    return answer;
    }
};