class Solution {
public:
    int numDistinct(string s, string t) {
        //2d dp problem
        //lets try making a matrix type and compare both strings and see if im able to get the subsequence
        int n = s.size();
        int m = t.size();
        
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        
        for (int i =0; i<=n; i++){
            dp[0][i]=1;
        }
        for (int i = 1; i<=m; i++){ // t -> rows
            for (int j = 1; j<=n; j++){ // s -> cols
                if(t[i-1]==s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1]; ///use it or skip it
                }else{
                    dp[i][j] = dp[i][j-1]; //cant use it so only skip it
                }
            }
        }
        return dp[m][n];
    }
};