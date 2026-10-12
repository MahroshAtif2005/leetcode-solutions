class Solution {
public:
    string validIPAddress(string queryIP) {
     //lets first identtify if it is a IPv4 address or a Ipv6
     int dots = 0;
     int colons = 0;
     for (char c : queryIP){
        if (c == '.'){
            dots++;
        }else if(c==':'){
            colons++;
        }
     }
     //now if its a right sized ipv4 address
     if(dots==3){
            string remaining = queryIP;
            while(remaining.find('.')!=string::npos){
                int pos = remaining.find('.');
                string part = remaining.substr(0,pos);

                if(part.empty()||part.size()>3){
                    return "Neither";
                }

                if(part.size()>1 && part[0]=='0'){
                     return "Neither";
                }
                
                for(char c: part){
                  if(!isdigit(c)){
                    return "Neither";
                  }
                }

                int num = stoi(part);
                if (num<0 || num>255){
                    return "Neither";
                }
                
                remaining = remaining.substr(pos+1);
            }

            //check the final section now after the '.'
            if (remaining.empty()||remaining.size()>3){
                return "Neither";
            }

            if (remaining.size() >= 2 && remaining[0] == '0') {
               return "Neither";
                 }

             for (char c : remaining) {
               if (!isdigit(c)) return "Neither";
              }

            int num = stoi(remaining);

            if (num < 0 || num > 255) {
                return "Neither";
              }

            return "IPv4";

          }else if(colons==7){

           string remaining = queryIP;

           while(remaining.find(':')!=string::npos){
              int pos = remaining.find(':');
              string part = remaining.substr(0,pos);

              if(part.empty() || part.size()>4){
                return "Neither";
              }
              
            
               for (char c : part) {
              if (!(isdigit(c) ||
               (c >= 'a' && c <= 'f') ||
               (c >= 'A' && c <= 'F'))) {
               return "Neither";
              }
               }

              remaining = remaining.substr(pos+1);         
            }

            //check the lats part now
            if(remaining.empty() || remaining.size()>4){
                return "Neither";
              }
              
              for(char c: remaining){
                //IF ALL THREE CONDITIONS ARE FALSE, ITS NEITHER
                if(! ((isdigit(c)) ||
                 (c >= 'a' && c <= 'f') ||
                 (c >= 'A' && c <= 'F')))       
                 {
                    return "Neither";
                }
              }         
        return "IPv6";
     }else{
        return "Neither";
     }

    }
};