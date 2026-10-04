class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       int maxNum = 0;
       for (int num : nums){
        maxNum = max(num, maxNum);
       }
 
        //points[i] = total points from taking all i's
        vector<int> points(maxNum+1,0);
        for (int num : nums){
            points[num]+= num;
        }
        
        vector<unsigned int> dp(maxNum+1,0);
        dp[0]=0;
        dp[1]=points[1];

        for (int i = 2; i<=maxNum; i++){
            dp[i]= max(dp[i-1],points[i]+dp[i-2]);
        }
        return dp[maxNum];
    }
};