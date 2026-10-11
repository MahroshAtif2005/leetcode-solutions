class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> map; //we will store prefix sum and its freq
     int count = 0;
     int prefixSum = 0;
     map[0] = 1;
    for (int num: nums){
      prefixSum += num;
      if(map.count(prefixSum-k)){
        count+=map[prefixSum-k];
      }
       map[prefixSum]++;
     }
     return count;
       }
};