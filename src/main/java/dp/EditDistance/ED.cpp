class Solution {

    int helper(string& s1, string& s2, int ind1, int ind2) {
        //Base Conditions
        //ending s1 "", defgh
        if(ind1 >= s1.length()) return s2.length() - ind2;
        if(ind2 >= s2.length()) return s1.length() - ind1;

        // chars are same
        if(s1[ind1] == s2[ind2])
            return helper(s1, s2, ind1 + 1, ind2 + 1);
        return 1 + min({helper(s1, s2, ind1 + 1, ind2 + 1), helper(s1, s2, ind1, ind2 + 1), helper(s1, s2, ind1 + 1, ind2)});
    }

public:
    int minDistance(string word1, string word2) {
        return helper(word1, word2, 0, 0);
    }
};