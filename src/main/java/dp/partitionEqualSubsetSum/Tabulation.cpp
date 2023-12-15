class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num: nums)
            sum += num;

        if(sum % 2 == 1) return false;
        int target = sum/2, n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (target + 1, false));

        //initialize all rows 0th column
        //target is 0
        for(int i=0; i<=n; i++)
            dp[i][0] = true;

        //zero elements but target is not zero
        for(int j=1; j <= target; j++)
            dp[0][j] = false;

        for(int i=1; i<=n; i++) { //elements
            for(int j=1; j<=target; j++) { //target
                //include curr element from nums
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]];
                //exclude curr element and check for other elements
                dp[i][j] = dp[i][j] || dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};