class Solution {
    void util(int n, int open, int close, string& s, vector<string>& comb) {
        if(open == n and close == n) {
            comb.push_back(s);
            return;
        }

        if(open < n) {
            s.push_back('(');
            util(n, open + 1, close, s, comb);
            s.pop_back();
        }
        if(close < n && close<open) {
            s.push_back(')');
            util(n, open, close + 1, s, comb);
            s.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> comb;
        util(n, 0, 0, s, comb);
        return comb;
    }
};