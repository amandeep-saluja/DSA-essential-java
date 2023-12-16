class Solution {
    bool helper(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        //both string and pattern is empty
        if(i<0 && j<0) return true;
        //pattern is empty but string is not
        if(j<0 && i>=0) return false;
        //string is empty but pattern is not
        if(i<0 && j>=0) {
            //**j**?**, ""
            //abc, ""
            //??ffsdadas, ""
            if(p[j]=='*') return helper(s, p, i, j-1, dp);// check if we have some more chars in pattern
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];

        //characters are same
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j] = helper(s, p, i-1, j-1, dp);

        //*
        if(p[j] == '*')
            return dp[i][j] = helper(s, p, i, j-1, dp) || helper(s, p, i-1, j, dp);

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return helper(s, p, n-1, m-1, dp);
    }
};