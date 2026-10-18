class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
   //go though the array nums if a element keeps increasing by 1 add it and add in hashmap
   //100 -> 1
   //200->1
   //1->2->-.3
   unordered_set<long long> set;
   for(int num : nums){
     set.insert(num);
   }

   int longest = 0;

   for(long long num : set){
    if(!set.count(num-1)){
      long long current = num;
      int length = 1;

      while(set.count(current+1)){
        current++;
        length++;
      }
      longest = max(longest,length);
    }
   }
   return longest;
}
};