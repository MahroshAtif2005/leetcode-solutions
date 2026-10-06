class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //ok so we need the letter logs before the digit logs
        //and letter logs are sorted by content
        //if content is same then by identifier
        
        vector<string> letters;
        vector<string> digits;
        for (int i = 0; i<logs.size(); i++){
           int pos = logs[i].find(' ');
           if(logs[i][pos+1]>='0' && logs[i][pos+1]<='9'){
              digits.push_back(logs[i]);
           }
           else{
            letters.push_back(logs[i]);
           }
        }
        // now i need to sort the letters array first without the identifier and if match then with the identifier
        sort(letters.begin(),letters.end(),[](string& a, string& b){
          int posA = a.find(' ');
          int posB = b.find(' ');

          if(a.substr(posA+1,a.size()-1)>b.substr(posB+1,b.size())){
            return false;
          }
          else if (a.substr(posA+1,a.size()-1)==b.substr(posB+1,b.size())){
             if(a.substr(0,posA)>b.substr(0,posB)){
             return false;
               }else{
                return true;
               }
          }else{
            return true;
          }
        });
        //now merge both arrays
        letters.insert(letters.end(),digits.begin(),digits.end());
        return letters;
    }
};