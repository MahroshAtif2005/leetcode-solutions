class Solution {
public:
    int myAtoi(string s) {
      /* Skip leading spaces using a while loop.
       Check the sign: '-' means negative, '+' means positive. Otherwise assume positive.
       Read digits while s[i] is between '0' and '9'.
       Build the number using num = num * 10 + digit.
       Handle integer overflow by clamping the result to INT_MIN or INT_MAX.
       Return the number with the correct sign. */

     int i = 0;
     int sign = 1;
     long long number = 0;

     //check leading spaces
     while(i<s.size() && s[i]==' '){
        i++;
     }
     //check if leading 0's
     if(i<s.size() && s[i]=='-'){
        sign = -1;
        i++;
      }else if (i < s.size() && s[i] == '+') {
            i++;
        }

        //read digits
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            int digit = s[i] - '0';
            if(number > (INT_MAX-digit)/10){
                if(sign==-1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            number = number * 10 +digit;
            i++;
        }

        return number*sign;
    }
};