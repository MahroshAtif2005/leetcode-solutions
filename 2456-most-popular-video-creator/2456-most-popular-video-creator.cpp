class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,   vector<string>& ids, vector<int>& views) {
 // store name, freq and index in hashmap
  unordered_map<string,pair<long long,int>> freq;

  for (int i = 0; i<creators.size(); i++){
     if(!freq.count(creators[i])){
      freq[creators[i]] = {views[i],i};
     }else{
      freq[creators[i]].first += views[i];

      int prevIndex = freq[creators[i]].second;

      if(views[i]>views[prevIndex] || 
        (views[i]==views[prevIndex] && ids[i]<ids[prevIndex])){
          freq[creators[i]].second = i;
        }
     }
  }

  //okay so now in the hashmap we have the freq of the students and we have the studens with the lexographically smaller id, now we just have to extract the students with the highest freq and their ids if two students have same freq all both in tha vector
 
  long long maxViews = 0;
  int index = 0;
  for (auto& entry: freq){
    maxViews = max(maxViews,entry.second.first);
  }
  //loop though freq again to extract ids
  vector<vector<string>> answer;
  for(auto& entry : freq){
    if (maxViews == entry.second.first){
      int index = entry.second.second;
      answer.push_back({creators[index],ids[index]});
    }
  }
 return answer;
 }

};