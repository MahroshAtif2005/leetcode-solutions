class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());

        int n = s.size();

        vector<bool> dp(n+1,false);
        dp[0] = true;

        for (int i = 1; i<=n; i++){
            for (int j = 0; j<i; j++){
                //s.substr(startingIndex, length)
                string word = s.substr(j,i - j);
                //Is the LEFT part already valid, AND is the RIGHT part a dictionary word?
                if (dp[j] && words.contains(word)){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};