class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";

        for (int i = 0; i<s.size(); i++){
            char c = tolower(s[i]);
            if(isalnum(c)){
                word+=c;
            }
        }

        int start = 0;
        int end = word.size()-1;

        while(start<=end){
            if(word[start]!=word[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};