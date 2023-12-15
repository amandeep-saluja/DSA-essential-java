class Solution {

    int helper(string& s1, string& s2, int ind1, int ind2, vector<vector<int>> & dp) {
        //Base Conditions
        //ending s1 "", defgh
        if(ind1 >= s1.length())
            return s2.length() - ind2;

        //ending s2 "", absds
        if(ind2 >= s2.length())
            return s1.length() - ind1;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        // chars are same
        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = helper(s1, s2, ind1 + 1, ind2 + 1, dp);

        return dp[ind1][ind2] = 1 + min({
                        helper(s1, s2, ind1 + 1, ind2 + 1, dp),
                        helper(s1, s2, ind1, ind2 + 1, dp),
                        helper(s1, s2, ind1 + 1, ind2, dp)
                    });
    }

public:
    int minDistance(string word1, string word2) {
        int n= word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(word1, word2, 0, 0, dp);
    }
};