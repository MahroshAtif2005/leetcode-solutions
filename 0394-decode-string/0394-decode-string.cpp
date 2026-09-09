class Solution {
public:
    string decodeString(string s) {
    stack<int> numbers;
    stack<string> prevString;

    string currentString = "";
    int currentNum = 0;

    for (char c : s){
        if(isdigit(c)){
            currentNum = currentNum * 10 + (c-'0');
        }else if(c == '['){
            numbers.push(currentNum);
            prevString.push(currentString);

            currentNum = 0;
            currentString = "";
        }else if(c == ']'){
            int repeatCount = numbers.top();
            numbers.pop();
            string previous = prevString.top();
            prevString.pop();
            string repeated = "";
            for (int i = 0; i<repeatCount;i++){
                repeated+=currentString;
            }
            currentString = previous+repeated;
        }else{
            currentString+=c;
        }
    }
    return currentString;
    } 
};