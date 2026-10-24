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
        //k most freq words
        // so we can use a priority queue and custom sorting
        //put in hashmap first
        unordered_map<string,int> map;
        for(string word: words){
            map[word]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,Compare> pq;
        
        for(auto& entry: map){
            pq.push({entry.first,entry.second});
            if(pq.size()>k){
              pq.pop();
            }
        }

        vector<string> answer;

        while(!pq.empty()){
            string word = pq.top().first;
            pq.pop();
            answer.push_back(word);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};