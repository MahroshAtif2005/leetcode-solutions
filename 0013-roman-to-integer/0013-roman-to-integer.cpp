class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int> roman = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
       };
       
        int prev = roman[s[s.size()-1]];
        int sum = prev;

       for(int i=s.size()-2; i>=0; i--){
        if(roman[s[i]]>=prev){
          sum+=roman[s[i]];
        }else{
            sum-=roman[s[i]];
        }
          prev = roman[s[i]];
       }

       return sum;
    }
};