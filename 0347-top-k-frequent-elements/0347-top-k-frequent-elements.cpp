class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //space complexity o(n)
    //time compexity o(n log n) -> coz of the sorting
     unordered_map<int,int> map;
     for (int i = 0 ; i<nums.size(); i++){
        map[nums[i]]++;
     }
     //do bucket sort, where the index represent the frequency
     vector<vector<int>> freq(nums.size()+1);
     
     for (auto& entry: map){
        freq[entry.second].push_back(entry.first);
     }
    
    vector<int> answer;
    for (int i = nums.size(); i>=1;i--){
        for (int num : freq[i]){
           answer.push_back(num);
           if(answer.size()==k){
            return answer;
           }
        }
    }
    return answer;
    }
};