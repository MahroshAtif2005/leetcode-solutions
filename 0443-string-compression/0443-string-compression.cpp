class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0;
        char c = chars[0];
        int count = 0;
      while(i<chars.size()){
            while(i < chars.size() && chars[i]==c){
              count++;
               i++;   
            }
            if(count == 1){
                s+=c;
            }else{
               s += c;
               s += to_string(count);
            }
    
            if (i < chars.size()) {
              c = chars[i];
              count = 0;
              }
      }
    

      //lets put the string in the chars vector now;
      for(int i = 0; i<s.size(); i++){
        chars[i]=s[i];
      }
      return s.size();
    }
};