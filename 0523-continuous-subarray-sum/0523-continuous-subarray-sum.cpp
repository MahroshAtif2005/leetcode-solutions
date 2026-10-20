class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> map;

     map[0]=-1;

     int prefixSum = 0;
     int rem = 0;

     for(int i = 0; i<nums.size(); i++){
       prefixSum += nums[i];
       rem = prefixSum % k;
       if(map.count(rem)){
        if(i-map[rem]>=2){
            return true;
         }
       }else{
        map[rem]=i;
       }
     }
     return false;
    }
};