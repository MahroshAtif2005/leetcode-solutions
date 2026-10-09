class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> freq; // prefix sum and the number of times we encountered it
     int count = 0;
     freq[0] = 1;
     int prefixSum = 0;
     for (int i = 0; i<nums.size();i++){
        prefixSum+=nums[i];

        if(freq.count(prefixSum-k)){
            count+= freq[prefixSum-k];
        }
        
        freq[prefixSum]++;
     }
     return count;
    }
};