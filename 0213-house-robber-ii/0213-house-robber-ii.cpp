class Solution {
public:
    int robRange(vector<int>& nums, int start, int end){
        //using pointers instead of dp array to save space
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i<=end; i++){
            int current = max(prev1,nums[i]+prev2);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
       //same as house robber I but since its cyclic, check if the last is selected,
       // first shouldnt be and if first is then last shouldnt be
       int n = nums.size();
       if(n == 1){
        return nums[0];
       }

       return max(
        robRange(nums,0,n-2),//ignore last
        robRange(nums,1,n-1)//ignore first
       );
    }
};