0 -> n

class Solution {
    void util(vector<int>& nums, vector<vector<int>>& comb, vector<int>& temp, int i) {
        if(i == nums.size()) {
            comb.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[i]);
        util(nums, comb, temp, i+1);
        //dont pick
        temp.pop_back();
        util(nums, comb, temp, i+1);

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> comb;
        vector<int> temp;

        util(nums, comb, temp, 0);

        return comb;
    }
};

---------------------------------------------------------------------------------------------
n -> 0

class Solution {
    void util(vector<int>& nums, vector<vector<int>>& comb, vector<int>& temp, int i) {
        if(i < 0) {
            comb.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[i]);
        util(nums, comb, temp, i-1);
        //dont pick
        temp.pop_back();
        util(nums, comb, temp, i-1);

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> comb;
        vector<int> temp;

        util(nums, comb, temp, nums.size()-1);

        return comb;
    }
};