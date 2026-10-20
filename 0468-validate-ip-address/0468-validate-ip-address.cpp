class Solution {
public:
    string validIPAddress(string queryIP) {
      //lets first identify if a address is IPv4 or IPv6
      int dots = 0;
      int colons = 0;

      for (int i = 0; i<queryIP.size(); i++){
         if(queryIP[i]=='.'){
            dots++;
         }else if(queryIP[i]==':'){
            colons++;
         }
       }
       
       if(queryIP.empty()){
         return "Neither";
        }
       if(queryIP.back() == '.' || queryIP.back() == ':'){  //check for the    trailing . and :
          return "Neither";
        }

       //check for IPv4 address now
       if(dots==3 && colons == 0){
       
            stringstream ss(queryIP);
            string part;
            while(getline(ss,part,'.')){

            if(part.size() < 1 || part.size() > 3){
              return "Neither";
              }

                for(char c : part){
                    if(!isdigit(c)){
                        return "Neither";
                    }
                }

               if(part.size() > 1 && part[0] == '0'){
                 return "Neither";
                }
                int num = 0;
            try{
                 num = stoi(part);
            }catch(const exception& e){
                return "Neither";
            }

                if(num<0 || num>255){
                    return "Neither";
                }
            }
   
       return "IPv4";
       }

       //check for IPv6 address now
       if(colons==7 and dots==0){ //make sure the other is 0
     
            stringstream ss(queryIP);
            string part;

            while(getline(ss,part,':')){
             if(part==""){
                return "Neither";
             }
              if(part.size()<1 || part.size()>4){
                return "Neither";
              }
              for(char c: part){
                if(!isxdigit(c)){ //checks for hexadecimal 
                    return "Neither";
                }
              }
        }
        return "IPv6";
       }

       return "Neither";
    }
};