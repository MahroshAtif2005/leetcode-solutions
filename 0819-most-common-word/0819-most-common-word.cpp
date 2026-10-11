class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        //hashmap with its freq and a set
        //put banned words in a set
        unordered_set<string> set;
        unordered_map<string,int> freq;
        string word;

        for (string word: banned){
         set.insert(word);
        }

        int maxCount = 0;
        string mostCommonWord;

        for (int i = 0; i<paragraph.size();i++){
          char c = paragraph[i];
          if(isalpha(c)){
            word+=tolower(c);
          }else {
            if(!word.empty() && !set.count(word)){
            freq[word]++;
            }
             word = "";
          }
        }

        if (!word.empty() && !set.count(word)) {
            freq[word]++;
          }

        for (auto& entry: freq){
           if(entry.second>maxCount){
            maxCount = entry.second;
            mostCommonWord = entry.first;
           }
        }

        return mostCommonWord;
    }
};