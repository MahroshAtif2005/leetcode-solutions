class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        //Second, pop_back() does not return the value. You need to first get the last element with back(), then remove it with pop_back():
        for(string token : tokens){
            if(token == "+"){
               int num1 = stack.back();
               stack.pop_back();
               int num2 = stack.back();
               stack.pop_back();
               int ans = num1 + num2;
                  stack.push_back(ans);
            }else if(token=="-"){
               int num1 = stack.back();
               stack.pop_back();
               int num2 = stack.back();
               stack.pop_back();
               int ans = num2 - num1;
                  stack.push_back(ans);
            }else if(token=="*"){
               int num1 = stack.back();
               stack.pop_back();
               int num2 = stack.back();
               stack.pop_back();
               int ans = num1 * num2;
                   stack.push_back(ans);
            }else if(token=="/"){
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                int ans = num2 / num1;
                   stack.push_back(ans);
            }else{
           int num = stoi(token);//converts string to a integer
           stack.push_back(num);
            }
        }
        return stack.back();
    }
};