class Solution {
public:
    int rob(vector<int>& nums) {
        //same as house robber I but since its cyclic, check if the last is selected,
       // first shouldnt be and if first is then last shouldnt be
       int n = nums.size();
       if(n == 1){
        return nums[0];
       }
   
       vector<int> dp1(n,0);
       dp1[0]= nums[0];
       dp1[1]=max(nums[0],nums[1]);
       //case 1: ignore the last house
       for (int i = 2; i<=n-2; i++){
         dp1[i]= max(dp1[i-1],nums[i]+dp1[i-2]);
       }

       //case 2: ignore the first house
       vector<int> dp2(n,0);
       dp2[1]=nums[1];
       for (int j = 2;j<=n-1;j++){
          dp2[j]= max(dp2[j-1],nums[j]+dp2[j-2]);
       }
       
       return max(dp1[n-2],dp2[n-1]);
    }
};