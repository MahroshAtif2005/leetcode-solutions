class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int> map;
     for(int num: nums){
        map[num]++;
     }

     vector<vector<int>> freq(nums.size()+1);

     for(auto& entry: map){
        freq[entry.second].push_back(entry.first);
     }

     vector<int> answer;

     for(int i = freq.size()-1; i>=1; i--){
       for(int num: freq[i]){
        answer.push_back(num);
        if(answer.size()==k){
            return answer;
        }
       }
     }
     return answer;
    }
};