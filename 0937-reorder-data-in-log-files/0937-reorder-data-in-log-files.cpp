class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
     //lets first identify if a log is a letetr log or a digit log
     //if its a letter log, put it in the letter array
     //ignore the identifier and sort the letter array, if same content then sort by identifier
     // if its a digit log add it in the digit array
     vector<pair<string,string>> letters;
     vector<string> digits;

     for (int i = 0; i<logs.size(); i++){
        int pos = logs[i].find(' ');
        if(isdigit(logs[i][pos+1])){
            digits.push_back(logs[i]);
        }else{
            string content = logs[i].substr(pos+1);
            string identifier = logs[i].substr(0,pos);
            letters.push_back({identifier,content});
        }
     }

     sort(letters.begin(),letters.end(),[](auto& a,auto& b){
       if (a.second==b.second){
         return a.first<b.first;
       }
       return a.second<b.second;
     });

     //merging both arrays now
    vector<string> answer;
    for(auto& pair: letters){
        answer.push_back(pair.first + " " + pair.second);
    }
     for(string digit : digits){
        answer.push_back(digit);
    }
    
    return answer;
    }
};