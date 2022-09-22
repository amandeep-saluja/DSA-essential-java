package dp;

import java.util.Arrays;

public class FrogJump {

    public static int frogJumpRecursive(int N, int[] heights) {
        if (N <= 1) {
            return 0;
        }

        int left = frogJumpRecursive(N - 1, heights) + Math.abs(heights[N - 1] - heights[N - 2]);

        int right = Integer.MAX_VALUE;

        if (N > 2) {
            right = frogJumpRecursive(N - 2, heights) + Math.abs(heights[N - 1] - heights[N - 3]);
        }

        return Integer.min(left, right);
    }

    private static int helper(int N, int[] heights, int[] dp) {
        if (N <= 0) {
            return 0;
        }

        if (dp[N] != -1) {
//            System.out.println("Reuse: "+(N));
            return dp[N];
        }
        int left, right = Integer.MAX_VALUE;
        left = helper(N - 1, heights, dp) + Math.abs(heights[N] - heights[N - 1]);

        if (N > 1) {
            right = helper(N - 2, heights, dp) + Math.abs(heights[N] - heights[N - 2]);
        }

        return dp[N] = Integer.min(left, right);
    }

    public static int frogJumpRecursiveDP(int N, int[] heights) {
        int[] dp = new int[N + 1];
        Arrays.fill(dp, -1);
        return helper(N - 1, heights, dp);
    }

    public static int frogJumpLoopDP(int N, int[] heights) {
        int[] dp = new int[N + 1];
        Arrays.fill(dp, -1);

        // base case
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            int left = dp[i - 1] + Math.abs(heights[i] - heights[i - 1]);
            int right = Integer.MAX_VALUE;
            // at-least more than 2 stairs should be present to jump 2 steps
            if (i > 1) {
                right = dp[i - 2] + Math.abs(heights[i] - heights[i - 2]);
            }
            dp[i] = Integer.min(left, right);
        }

        return dp[N];
    }

    public static int frogJumpLoopDPOptimized(int N, int[] heights) {
        int last=0, secondLast = 0;

        for (int i = 1; i <= N; i++) {
            int left = last + Math.abs(heights[i] - heights[i - 1]);
            int right = Integer.MAX_VALUE;
            // at-least more than 2 stairs should be present to jump 2 steps
            if (i > 1) {
                right = secondLast + Math.abs(heights[i] - heights[i - 2]);
            }
            secondLast = last;
            last = Integer.min(left, right);
        }

        return last;
    }

    public static void main(String[] args) {
        int N = 4;

        int[] heights = new int[]{10, 20, 30, 10};

        System.out.println("Recursive: Min energy: " + frogJumpRecursive(N, heights));
        System.out.println("Recursive DP: Min energy: " + frogJumpRecursiveDP(N, heights));
        System.out.println("Loop DP: Min energy: " + frogJumpLoopDP(N - 1, heights));
        System.out.println("Loop DP Optimized: Min energy: " + frogJumpLoopDPOptimized(N - 1, heights));

        N = 6;

        heights = new int[]{30, 10, 60, 10, 60, 50};

        System.out.println("Recursive: Min energy: " + frogJumpRecursive(N, heights));
        System.out.println("Recursive DP: Min energy: " + frogJumpRecursiveDP(N, heights));
        System.out.println("Loop DP: Min energy: " + frogJumpLoopDP(N - 1, heights));
        System.out.println("Loop DP Optimized: Min energy: " + frogJumpLoopDPOptimized(N - 1, heights));
    }
}
