class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j] = minimum operations to convert the first i characters of word1 into the first j characters of word2
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 0; i<=m; i++){
            dp[i][0]=i;
        }
        for(int j = 0; j<=n; j++){
            dp[0][j]=j;
        }

        for (int i = 1; i<=m; i++){
            for (int j = 1; j<=n; j++){
                //if alst character already match
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                //last character dont match
                else{
                   int replace = dp[i-1][j-1];
                   int deleteChar = dp[i-1][j];
                   int insert = dp[i][j-1];

                   dp[i][j] = 1+min({replace,deleteChar,insert});
                }
            }
        }
        return dp[m][n];
    }
};