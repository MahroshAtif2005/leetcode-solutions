class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //lets create a dp array, that will keep track of the smallers way till now
        int rows = grid.size();
        int cols = grid[0].size();
        //rows and columns
        //hm idk maybe if we are doing smallest element till now we wont need a 2d dp
        vector<vector<int>> dp(rows,vector<int> (cols,0));
        dp[0][0]=grid[0][0];

        //first col can only come from above
        for (int i = 1; i<rows; i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //first row only comes from left
        for (int j = 1; j<cols; j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        
        //assumes every cell has two possible places to come from
        for (int i = 1; i<rows; i++){
            for (int j = 1; j<cols; j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};