class Solution {
public:

    int helper(string& s1, string& s2, int idx1, int idx2, vector<vector<int>>& dp) {

        if(idx1 >= s1.length() || idx2 >= s2.length())
            return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        //characters are same
        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = 1 + helper(s1, s2, idx1 + 1, idx2 + 1, dp);
        }

        //characters are not same
        return dp[idx1][idx2] = max(helper(s1, s2, idx1 + 1, idx2, dp), helper(s1, s2, idx1, idx2 + 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return helper(text1, text2, 0, 0, dp);
    }
};