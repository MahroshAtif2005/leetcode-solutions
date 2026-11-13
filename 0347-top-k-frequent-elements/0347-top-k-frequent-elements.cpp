class Solution {
public:

    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hashmap<element,freq>
        //shift the elements from hashmap in a vector, sort it and return top k  X-> N LOG N
        //priorityqueue we maintain a min heap of k and we pop the rest and yeah. n log k
        // or i can use a freq bucket too 
        
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size();i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto& entry: map){
            pq.push({entry.second,entry.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
       
       vector<int> answer;

       while (!pq.empty()){
        answer.push_back(pq.top().second);
        pq.pop();
       }

       reverse(answer.begin(),answer.end());
       
       return answer;
    }
};