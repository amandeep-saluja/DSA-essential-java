647. Palindromic Substrings

class Solution {
public:
    int f(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i>j) return false;
        if(i == j) return dp[i][j] = true;

        if(dp[i][j] != -1) return dp[i][j];

        f(i, j-1, s, dp);
        f(i+1, j, s, dp);

        if(s[i] == s[j] && (j == i+1 || f(i+1, j-1, s, dp))) {
            dp[i][j] = true;
        }
        else dp[i][j] = false;

        return dp[i][j];
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int count = 0;

        f(0, n-1, s, dp);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dp[i][j] == 1) count++;
            }
        }
        return count;
    }
};
