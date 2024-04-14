class Solution {
    int robUtil(vector<int>& nums, int start, int end) {
        if(start >= end) return 0;

        //rob
        int rob = nums[start] + robUtil(nums, start + 2, end);

        //dont rob
        int dontRob = robUtil(nums, start + 1, end);

        return max(rob, dontRob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(robUtil(nums, 0, n-1), robUtil(nums, 1, n));
    }
};