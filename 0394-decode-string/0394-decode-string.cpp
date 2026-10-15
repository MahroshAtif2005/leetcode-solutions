class Solution {
public:
    string decodeString(string s) {
    stack<int> numberStack;
    stack<string> stringStack;

    int repeatCount = 0;
    string currentString = "";

    for (int i = 0; i<s.size(); i++){
        if(isdigit(s[i])){
            repeatCount = repeatCount * 10 + (s[i]-'0');
        }
        else if(s[i]=='['){
            numberStack.push(repeatCount);
            stringStack.push(currentString);

            repeatCount = 0;
            currentString = "";
        }else if(s[i]==']'){
            int count = numberStack.top();
            numberStack.pop();
            string prevString = stringStack.top();
            stringStack.pop();

            string repeatedString = "";

            for (int i = 0; i<count; i++){
                repeatedString += currentString;
            }

             currentString = prevString + repeatedString;
        }else{
            currentString += s[i];
        }
    } 
    return currentString;
    }
};