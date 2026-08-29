class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window
        int left = 0;
        int minSubarray =  INT_MAX;
        int sum = 0;

        for (int right = 0; right<nums.size(); right++){
            sum += nums[right];
            while(sum>=target){
                minSubarray = min(right-left+1,minSubarray);
                sum -= nums[left];
                left++;
            }
        }
        if(minSubarray == INT_MAX){
            return 0;
        }
        return minSubarray;
    }
};