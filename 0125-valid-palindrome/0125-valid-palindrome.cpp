class Solution {
public:
    bool isPalindrome(string s) {
      //i can do this by creating a new string
      //but to save space lets try editing the same string
      int start = 0;
      int end = s.size() - 1;

      while(start<end){

        if(s[start]== ' '|| !isalnum(s[start])){
            start++;
            continue;
        }

        if(s[end]== ' ' || !isalnum(s[end])){
            end--;
            continue;
        }

        if(tolower(s[start])!=tolower(s[end])){
            return false;
        }

        start++;
        end--;

      }

      return true;
    }
};