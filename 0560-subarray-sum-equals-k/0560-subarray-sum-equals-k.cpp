class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //okay so i can go through the array suing two for loops and check for contigenosy but that will take 0(n2) time, so what else i can do
        //lets see what if i use a hashmap uhh , i keep a prefix sum and put that prefix sum in the hashmap and then with every value i subtrack from f the prefix sum and if the prefix sum is in the hashmap then we add 1 in count, um the hashmap should also be containing freq-> this will reduce the time complexity to o(n) prolly, let try
        int count = 0;
        unordered_map<int,int> map;
        int prefixSum = 0;

        map[0] = 1;

        for(int num: nums){
          prefixSum += num;
          if(map.count(prefixSum-k)){
            count += map[prefixSum-k];
          }  
            map[prefixSum]++;
        }
        return count;
    }
};