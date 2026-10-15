class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     //hashmap + priority queue
     unordered_map<int,int> freq;
     for (int i = 0; i<nums.size(); i++){
        freq[nums[i]]++;
     }
    //lets do by bucket sort now
    //keep the index as teh freq
    int n = nums.size();

    vector<vector<int>> bucket(n + 1); //beacuse multiple numvers can have same freq
    
    for (auto& entry : freq){
         bucket[entry.second].push_back(entry.first);
    }
    // 0 1 2 3 4 5
    // -1 3 2 -1 -1 -1
     
     vector<int> answer;

   for (int i = n; i >= 1; i--) {
    for (int num : bucket[i]) {
        answer.push_back(num);

        if (answer.size() == k) {
            return answer;
        }
    }
}
     
     return answer;
    }
};