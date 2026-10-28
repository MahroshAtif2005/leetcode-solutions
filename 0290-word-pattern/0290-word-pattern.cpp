class Solution {
public:
    bool wordPattern(string pattern, string s) {
       unordered_map<char,string> charToWord;
       unordered_map<string,char> wordToChar;

       stringstream ss(s);
       string line;

       vector<string> words;

       while(ss>>line){
        words.push_back(line);
       }

       if(pattern.size()!=words.size()){
          return false;
       }

       for(int i = 0; i<pattern.size(); i++){
          char c = pattern[i];
          string word = words[i];

          if(charToWord.count(c) && charToWord[c]!=word){
            return false;
          }

          if(wordToChar.count(word) && wordToChar[word]!=c){
            return false;
          }

          charToWord[c]=word;
          wordToChar[word]=c;
       }
       return true;
     }
};