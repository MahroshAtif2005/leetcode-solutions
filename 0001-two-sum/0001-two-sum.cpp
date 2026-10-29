class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> map; //stores number and its index
     int find = 0;
     for(int i = 0; i<nums.size(); i++){
        find = target - nums[i];
        if(map.count(find)){
            return {map[find],i};
        }else{
            map.insert({nums[i],i});
        }
     }
     return {};
    }
};