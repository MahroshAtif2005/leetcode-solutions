class Solution {
public:
    struct Compare{
        bool operator()(const pair<string,int>& a, const pair<string,int>& b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int> freq;
      for(string word:words){
        freq[word]++;
      }
      priority_queue<pair<string,int>,vector<pair<string,int>>,Compare> pq;

      for(auto element : freq){
        pq.push({element.first,element.second});
        if(pq.size()>k){
            pq.pop();
        }
      }
      vector<string> answer;
      while(!pq.empty()){
       answer.push_back({pq.top().first});
       pq.pop();
      }

      reverse(answer.begin(),answer.end());
      return answer;
    }
};