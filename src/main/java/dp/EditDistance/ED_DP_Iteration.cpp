class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // Initial conditions

        //i operations will be performed for (abcde, "") string
        for(int i=0; i<=n; i++)
            dp[i][0] = i;

        //j operations will be performed for ("", dsadsa) string
        for(int j=0; j<=m; j++)
            dp[0][j] = j;

        //Iteration:
        //loop for [1 to n] rows and [1 to m] columns
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                //chars are same
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                //chars are diff
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }

        return dp[n][m];
    }
};