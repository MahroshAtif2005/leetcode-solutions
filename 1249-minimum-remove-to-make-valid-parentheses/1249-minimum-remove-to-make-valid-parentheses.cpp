class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //go through the string
        //if see a bracket add index in the stack, if closed put it out, at the end if any ndices left in the stack, build the final string but without it
          unordered_set<int> set;
       stack<int> st;
       for(int i =0 ; i<s.size(); i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){ 
            if(!st.empty()){ //we have to use this condition in case the first bracket we incounter is a closing bracket, if it is directly add it to the invalid bracket set
            st.pop();
            }else{
                set.insert(i);
            }
        }else{
            continue;
        }
       }

       string answer;

       while(!st.empty()){
        set.insert(st.top());
        st.pop();
       }

      for(int i = 0; i<s.size(); i++){
        if(!set.contains(i)){
            answer+=s[i];
        }
      }
      return answer;
    }
};