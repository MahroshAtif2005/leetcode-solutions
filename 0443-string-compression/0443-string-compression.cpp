class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0;
        char c = chars[0];
        int count = 0;
        int write = 0;
      while(i<chars.size()){
            while(i < chars.size() && chars[i]==c){
              count++;
               i++;   
            }
            if(count == 1){
                chars[write++]=c;
            }else{
               chars[write] = c;
               write++;
               string num = to_string(count);

               for(char digit : num){
                  chars[write++] = digit;
               }
            }
    
            if (i < chars.size()) {
              c = chars[i];
              count = 0;
              }
      }
    

      //lets put the string in the chars vector now;
      return write;
    }
};