class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp ques -> feels like the robber question
        //lets start wth the base case
        int n = cost.size();
        vector<int> dp(n+1,0);

        dp[0]=cost[0];
        dp[1]=cost[1];

        for (int i = 2; i<n; i++){
            dp[i]= min(dp[i-1],dp[i-2])+cost[i];
        }    
        //Of the two stairs that can reach the top, return whichever one was cheaper to reach
        return min(dp[n-1],dp[n-2]);   
    }
};