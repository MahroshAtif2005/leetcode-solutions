class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int> freq;
      for(string word: words){
        freq[word]++;
      }
      vector<pair<int,string>> arr;
      for (const auto& entry : freq){
        arr.push_back({entry.second,entry.first});
      }
      //custom sort
      sort(arr.begin(), arr.end(),[](auto& a, auto& b){
         if(a.first>b.first){
            return true;
         }else if(a.first<b.first){
            return false;
         }else{
            if(a.second<b.second){
                return true;
            }else{
                return false;
            }
         }
      });

      vector<string> answer;
      for (int i = 0 ; i < k; i++){
       answer.push_back(arr[i].second);
      }
      return answer;
    }
};