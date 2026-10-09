class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //put all elements in a hashset and see if it adds 
        unordered_map<int,int> map; //number and its index
        for (int i = 0;i<nums.size(); i++){
            int find = target - nums[i];
            if(map.count(find)){
                return {map[find],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};