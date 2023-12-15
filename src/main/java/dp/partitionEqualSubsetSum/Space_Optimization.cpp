class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num: nums)
            sum += num;

        if(sum % 2 == 1) return false;
        int target = sum/2, n = nums.size();

        vector<int> prev(target+1, false);
        vector<int> curr(target+1, false);
        prev[0] = true; //no element and target is 0
        curr[0] = true; //1 element but target is 0

        for(int i=1; i<=n; i++) { //elements
            for(int j=1; j<=target; j++) { //target
                //include curr element from nums
                if(nums[i-1] <= j)
                    curr[j] = prev[j-nums[i-1]];
                //exclude curr element and check for other elements
                curr[j] = curr[j] || prev[j];
            }
            prev = curr;
        }
        return curr[target];
    }
};