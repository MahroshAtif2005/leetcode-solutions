class Solution {
public:
    int robRange(vector<int>& nums, int start,int end){
        //dp solution without dp array so espace compexity remians o(1)
        int prev = 0;
        int prev2 = 0;
        int current = 0;

        for(int i = start; i<=end; i++){
            current = max(prev,prev2+nums[i]);
            prev2 = prev;
            prev = current;
        }
        return prev; //we return prev cz at the end its the last no returing the value
    }
   
    int rob(vector<int>& nums) {
     int n = nums.size();
     if(n==1){
        return nums[0];
     }
     //1 loop with 1 first house and 1 with last
     return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }
};