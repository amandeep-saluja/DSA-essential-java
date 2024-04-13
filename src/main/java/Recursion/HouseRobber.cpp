0 -> n

class Solution {
    int robUtil(vector<int>& nums, int house) {
        if(house>=nums.size()) return 0;

        int rob = nums[house] + robUtil(nums, house+2);
        int dontRob = robUtil(nums, house+1);

        return max(rob, dontRob);
    }
public:
    int rob(vector<int>& nums) {
        return robUtil(nums, 0);
    }
};
------------------------------------------------------------
n -> 0

class Solution {
    int robUtil(vector<int>& nums, int house) {
        if(house<0) return 0;

        int rob = nums[house] + robUtil(nums, house-2);
        int dontRob = robUtil(nums, house-1);

        return max(rob, dontRob);
    }
public:
    int rob(vector<int>& nums) {
        return robUtil(nums, nums.size()-1);
    }
};

--------------------------------------------------------------

