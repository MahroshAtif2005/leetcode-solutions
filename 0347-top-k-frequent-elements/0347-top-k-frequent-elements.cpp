class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     //hashmap + priority queue
     unordered_map<int,int> freq;
     for (int i = 0; i<nums.size(); i++){
        freq[nums[i]]++;
     }
     //freq,number
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

     for (auto& entry: freq){
        pq.push({entry.second,entry.first});
        if(pq.size()>k){
            pq.pop();
        }
     }
     //turn in the array
     vector<int> answer;
     while(!pq.empty()){
        answer.push_back(pq.top().second);
        pq.pop();
     }
     return answer;
    }
};