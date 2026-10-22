class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int totalSum = 0;
       int leftSum = 0;

       for(int num: nums){
        totalSum += num;
       }

       for(int i = 0; i<nums.size(); i++){
        
          if(totalSum-leftSum-nums[i]==leftSum){ //subtract nums[i] also cz we cant include pivot
            return i;
          }
          leftSum+= nums[i];
       }
       return -1;
    }
};