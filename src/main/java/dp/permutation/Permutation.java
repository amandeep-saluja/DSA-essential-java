package dp.permutation;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(nums, 0, res);
        return res;
    }

    private void helper(int[] nums, int idx, List<List<Integer>> res) {
        if (idx == nums.length) {
            List<Integer> temp = new ArrayList<>();
            for (int n : nums) {
                temp.add(n);
            }
            res.add(temp);
            return;
        }

        for (int i = idx; i < nums.length; i++) {
            swap(nums, idx, i);
            helper(nums, idx + 1, res);
            swap(nums, idx, i);
        }
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 3};
        System.out.println(solution.permute(nums));
    }
}