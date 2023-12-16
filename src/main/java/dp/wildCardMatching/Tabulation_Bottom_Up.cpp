class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, false));

        dp[0][0] = true;
        //initial conditions
        //pattern is empty, string is not
        for(int i=1; i<=n; i++)
            dp[i][0] = false;
        //string is empty, pattern is not
        for(int j=1; j<=m; j++) {
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-1];
            else dp[0][j] = false;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                //chars are same
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};