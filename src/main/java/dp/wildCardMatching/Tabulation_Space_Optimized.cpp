class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<bool> prev(m+1, false);
        vector<bool> curr(m+1, false);

        prev[0] = true;
        curr[0] = false;

        //string is empty, pattern is not
        for(int j=1; j<=m; j++) {
            if(p[j-1]=='*')
                prev[j] = prev[j-1];
            else prev[j] = false;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                //chars are same
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    curr[j] = prev[j-1];
                else if(p[j-1] == '*')
                    curr[j] = prev[j] || curr[j-1];
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};