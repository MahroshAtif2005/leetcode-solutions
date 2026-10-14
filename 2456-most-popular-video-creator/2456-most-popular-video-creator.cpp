class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        //use a hashmap, store the name as unique identifier and the count of views

        unordered_map<string,long long> map;
        for (int i = 0; i<creators.size(); i++){
           map[creators[i]]+=views[i];
        }
        
        long long mostViews = 0;
        
        set<string> mostPopular;
        for(auto& entry: map){
            if(entry.second>mostViews){
                mostViews = entry.second;
                mostPopular.clear();
                mostPopular.insert(entry.first);
            }else if (entry.second == mostViews) {
                mostPopular.insert(entry.first);
            }
        }
       
      //key is the creators name and the pair for highest invidual video views and its id
      unordered_map<string, pair<int, string>> bestVideo; 

      for(int i = 0; i<creators.size();i++){
        if (!bestVideo.count(creators[i]) ||
           views[i] > bestVideo[creators[i]].first ||
          (views[i] == bestVideo[creators[i]].first &&
          ids[i] < bestVideo[creators[i]].second)) {

           bestVideo[creators[i]] = {views[i], ids[i]};

          }
      }
    
      vector<vector<string>> answer;

     for (auto& creator : mostPopular) {
       answer.push_back({creator, bestVideo[creator].second});
      } 

      return answer;
    }
};