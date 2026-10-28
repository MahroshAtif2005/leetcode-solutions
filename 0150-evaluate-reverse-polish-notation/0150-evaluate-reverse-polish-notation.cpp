class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> st;

     for(string token : tokens){
        if(token=="+" || token =="-" || token == "*" || token =="/"){
          
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                int ans; 

                if(token=="+"){
                    ans = num2+num1;
                }else if(token =="-"){
                    ans = num2-num1;
                }else if(token=="*"){
                    ans = num2*num1;
                }else{
                    ans = num2/num1;
                }

                st.push(ans);
     
        }else{
            st.push(stoi(token));
        }
     }

     return st.top();
    }
};