class Solution {
public:
    string reverseOnlyLetters(string s) {
        //use two pointers chage lettrs if nto a letter check by isalpha js dp +1
      int start = 0;
      int end = s.size()-1;

      while(start<end){
        if(!isalpha(s[start])){
            start++;
        }else if(!isalpha(s[end])){
            end--;
        }else{
            char temp = s[start];
            s[start]=s[end];
            s[end] = temp;
            start++;
            end--;
        }  
      }
      return s;
    }
};