class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        if(n == 0) return m;
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        //dp[i-1] -> prev
        //dp[i] -> curr

        // Initial conditions

        //j operations will be performed for ("", dsadsa) string
        for(int j=0; j<=m; j++)
            prev[j] = j;

        //Iteration:
        //loop for [1 to n] rows and [1 to m] columns
        for(int i=1; i<=n; i++) {
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                //chars are same
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                //chars are diff
                else
                    curr[j] = 1 + min({prev[j-1], prev[j], curr[j-1]});
            }
            prev = curr;
        }

        return curr[m];
    }
};