class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> ranges;
      int i = 0;
      while(i<nums.size()){
        int start = nums[i];
         while(i<nums.size()-1 && (long long)nums[i+1]-nums[i]==1){
            i++;
         }
         int end = nums[i];
         if(start==end){
            ranges.push_back(to_string(start));
         }else{
         ranges.push_back(to_string(start) + "->" + to_string(end));
         }
         i++;
      }
      return ranges;
    }
};