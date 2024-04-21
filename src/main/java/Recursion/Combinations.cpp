class Solution {
    void util(int n, int k, vector<int>& res, vector<vector<int>>& comb, int idx) {
        if(res.size() == k) {
            comb.push_back(res);
            return;
        }

        for(int i=idx; i<=n; i++) {
            res.push_back(i);
            util(n, k, res, comb, i+1);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> comb;
        vector<int> res;
        util(n, k, res, comb, 1);
        return comb;
    }
};
----------------------------------------------------------------------------------------
