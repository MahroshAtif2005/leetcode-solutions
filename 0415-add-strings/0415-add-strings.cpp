class Solution {
public:
    string addStrings(string num1, string num2) {
      int p1 = num1.size()-1;
      int p2 = num2.size()-1;
      int carry = 0;
      string result;

      while(p1>=0 || p2>=0 || carry>0){
        int sum = carry;
        if(p1>=0){
            sum += num1[p1] - '0';
            p1--;
        }
        if(p2>=0){
            sum += num2[p2] - '0';
            p2--;
        }

        result += '0' + sum % 10; //gives the last digit
        carry = sum/10; //gives the first digit of string the one we carrying
      }
      reverse(result.begin(),result.end());
      return result;
    }
};