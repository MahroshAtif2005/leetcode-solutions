class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     //lets store the prefix sum of the arrays in a hashmap and count of how many times it appread
     //will this work for negative numbers too?
     unordered_map<int,int> freq;
     int count = 0;
     int prefixSum = 0;
     freq[0] = 1;
     for (int i = 0; i<nums.size(); i++){
       prefixSum += nums[i];
       if(freq.count(prefixSum-k)){
          count+= freq[prefixSum-k];
       }
        freq[prefixSum]++;
     }
     return count;
       }
};