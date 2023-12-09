class Solution {

    void helper(int n, int idx, int k, vector<vector<int>>& res, vector<int>& temp) {
        //base
        if(k==temp.size()) {
            res.push_back(temp);
            return;
        }
        if(idx>n) return;

        //include
        temp.push_back(idx);
        helper(n, idx+1, k, res, temp);
        temp.pop_back();

        //exclude
        helper(n, idx+1, k, res, temp);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(n, 1, k, res, temp);
        return res;
    }
};