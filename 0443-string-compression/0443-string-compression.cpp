class Solution {
public:
    int compress(vector<char>& chars) {
     int i = 0;
     int write = 0;
     int count = 0;
     int num = 0;

     char c = chars[0];

     while(i<chars.size()){

         while(i<chars.size()&&chars[i]==c){
            i++;
            count++;
         }

         if(count==1){
            chars[write++] = c;
         }
        
       
       if(count>1){
         chars[write++] = c;
        string num = to_string(count);
        for(char digit : num){
            chars[write++] = digit;
        }
       }
       
       if(i<chars.size()){
         c = chars [i];
         count = 0;
       }
     }
     return write;
    }
};