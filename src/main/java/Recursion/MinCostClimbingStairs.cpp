n->0

class Solution {
    int helper(vector<int>& cost, int ind) {
        if(ind<0) return 0;

        return cost[ind] + min(helper(cost, ind-1), helper(cost, ind-2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(helper(cost, n-1), helper(cost, n-2));
    }
};


--------------------------------------------------------------------------------
0->n

class Solution {
    int helper(vector<int>& cost, int ind) {
        if(ind>=cost.size()) return 0;

        return cost[ind] + min(helper(cost, ind+1), helper(cost, ind+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost, 0), helper(cost, 1));
    }
};

---------------------------------------------------------------------------------
n->0

class Solution {
    int helper(vector<int>& cost, int ind) {
        if(ind<=0) return 0;

        return min(cost[ind-1] + helper(cost, ind-1), ind<2 ? 0 : cost[ind-2] + helper(cost, ind-2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return helper(cost, cost.size());
    }
};