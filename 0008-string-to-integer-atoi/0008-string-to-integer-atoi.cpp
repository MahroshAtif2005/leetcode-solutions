class Solution {
public:
    int myAtoi(string s) {
      int sign = 1;
      long long number = 0;
      int i = 0;

       while(i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle optional sign
        if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while(i < s.size() && s[i]>='0' && s[i]<='9'){
          int digit = s[i]-'0';
          if(number * 10 + digit > INT_MAX){
            if(sign == 1){
            return INT_MAX;
            }else if(sign == -1){
            return INT_MIN;
            }
          }
          number = number * 10 + digit;
          i++;
      }

      return number*sign;
    }
};