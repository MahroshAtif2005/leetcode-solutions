class Solution {
public:

    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hashmap<element,freq>
        //shift the elements from hashmap in a vector, sort it and return top k  X-> N LOG N
        //priorityqueue we maintain a min heap of k and we pop the rest and yeah. n log k
        // or i can use a freq bucket too  0(n) time
        
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size();i++){
            map[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1); // index should be the freq and the number stored in array then

        for(auto& entry: map){
            bucket[entry.second].push_back(entry.first);
        }

        vector<int> ans;
        
        for(int i = bucket.size()-1; i>=0; i--){
            for(int num : bucket[i]){
            ans.push_back(num);
            
            if(ans.size()==k){
                return ans;
            }
            }
        }

        return ans;
    }
};