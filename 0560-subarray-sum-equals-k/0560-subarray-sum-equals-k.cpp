class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     //use a hashmap to store prefix sum
     unordered_map<int,int> freq;
     int sum = 0;
     int count = 0;
     
     freq[0]=1; //empty prefix sum occurs once

     for (int num: nums){
        sum  += num;
        if(freq.count(sum-k)){
            count += freq[sum-k];
        }
        freq[sum]++;
     }

    return count;
       }
};