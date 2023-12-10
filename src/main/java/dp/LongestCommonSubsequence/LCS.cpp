class Solution {
public:

    int helper(string& s1, string& s2, int idx1, int idx2) {

        if(idx1 >= s1.length() || idx2 >= s2.length())
            return 0;

        //characters are same
        if(s1[idx1] == s2[idx2]) {
            return 1 + helper(s1, s2, idx1 + 1, idx2 + 1);
        }

        //characters are not same
        return max(helper(s1, s2, idx1+1, idx2), helper(s1, s2, idx1, idx2+1));

    }

    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1, text2, 0, 0);
    }
};