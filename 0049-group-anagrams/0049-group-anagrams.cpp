class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> map;
      int count = 0;
      vector<vector<string>> answer;
 
      for(string word : strs){
        string beforeSort = word;
        sort(word.begin(),word.end());
        map[word].push_back(beforeSort);
      }
       for (const auto& entry: map){
        answer.push_back(entry.second);
      }
      return answer;
    }
};