class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> letters;

        int num = 0;
        string word = "";

        for (int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0'); 
        }else if(s[i]=='['){
                counts.push(num);
                letters.push(word);
                num = 0;
                word = "";
        }else if(s[i]==']'){
                int number = counts.top();
                counts.pop();

                string previous = letters.top();
                letters.pop();
                string repeated = "";

                for (int j = 0; j < number; j++) {
                    repeated += word;
                }

                word = previous + repeated;

        }else{
                word += s[i];
        }
        }
        return word;
    }
};