class Solution {
public:
    string validIPAddress(string queryIP) {
        //lets first try to identify if its a IPv4, IPv6 pattern or neither, then we will check if the address meets all the requirements of the network
        int dots = 0;
        int colons = 0;
        for (int i = 0; i<queryIP.size(); i++){
          if (queryIP[i] == '.') dots++;
          if (queryIP[i] == ':') colons++;
        }

            //lets check for ipv4
             if(dots==3){
                //TO CHECK IF LAST CHAR IS A TRAILING .
                if (queryIP.back() == '.') {
                   return "Neither";
                   }

              stringstream ss(queryIP);
              string piece;
              //ss is the whole stream and piece is one piece
              while(getline(ss,piece,'.')){
                if(piece.empty()){
                   return "Neither";
                   }
                   
                if(piece.size()>1 && piece[0]=='0'){
                    return "Neither";
                }

                  if (piece.size() > 3) {
                     return "Neither";
                     }
                     
              for (char c : piece) {
                if (!isdigit(c)) {
                    return "Neither";
                     }
                   }
                int num= stoi(piece);
                if(num<0 || num> 255){
                      return "Neither";
                }
                //valid continue checking
                }
                   return "IPv4";
              } else if (colons ==7){
                  //TO CHECK IF LAST CHAR IS A TRAILING  :
                if (queryIP.back() == ':') {
                   return "Neither";
                   }

                 stringstream ss(queryIP);
                 string piece;
                 while (getline(ss,piece,':')){
                    if (piece.size()<1 || piece.size()>4){
                        return "Neither";
                    }
                    for(char c : piece){
                     bool digit = (c >= '0' && c <= '9');
                     bool lower = (c >= 'a' && c <= 'f');
                     bool upper = (c >= 'A' && c <= 'F');

                      if (!(digit || lower || upper)) {
                          return "Neither";
                        }
                      }
                    }
                     return "IPv6";
              }
                else{
                    return "Neither";
                }
    }
};