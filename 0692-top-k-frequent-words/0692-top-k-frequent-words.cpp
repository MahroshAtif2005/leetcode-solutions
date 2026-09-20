class Solution {
public:
    struct compare{
        bool operator()(const pair<int,string>& a,const pair<int,string>& b){
           if(a.first==b.first){
            return a.second<b.second;
           }
           return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for (string word: words){
                map[word]++;
        }
         priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
          for (auto element : map){
            pq.push({element.second, element.first});
            if(pq.size()>k){
                pq.pop();
            }
          }
          vector<string> answer;
          //higher freq comes first
          //same freq->sort in lexgraphically sorted order
        while(!pq.empty()){
          answer.push_back(pq.top().second);
          pq.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};