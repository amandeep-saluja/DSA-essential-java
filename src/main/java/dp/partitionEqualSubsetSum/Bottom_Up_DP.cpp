class Solution {

    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target==0) return true;
        if(idx>=nums.size() || target<0) return false;

        if(dp[idx][target] != 2) return dp[idx][target];

        //include
        if(helper(idx+1, target-nums[idx], nums, dp))
            return dp[idx][target] = true;

        //exclude
        if(helper(idx+1, target, nums, dp))
            return dp[idx][target] = true;

        return dp[idx][target] = false;
    }

public:
    bool canPartition(vector<int>& nums) {
        //check if sum is odd -> return false
        int n = nums.size();
        int sum = 0;
        for(int num: nums)
            sum+=num;

        if(sum%2!=0) return false;

        int target = sum/2; // subset sum
        vector<vector<int>> dp(n, vector<int>(target+1, 2));
        //find some elements whose sum is target

        //are there any number of elements such that their sum is target
        //pick 1 -> 10 [5,11,5]
        //dont pick -> 11 [5,11,5]
        return helper(0, target, nums, dp);
    }
};