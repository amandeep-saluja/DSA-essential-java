package dp;

import java.util.Arrays;

public class FrogJump {

    public static int frogJumpRecursive(int N, int[] heights) {
        if (N<=1) {
            return 0;
        }

        int left = frogJumpRecursive(N - 1, heights) + Math.abs(heights[N-1] - heights[N-2]);

        int right = Integer.MAX_VALUE;

        if(N>2) {
            right = frogJumpRecursive(N - 2, heights) + Math.abs(heights[N-1] - heights[N-3]);
        }

        return Integer.min(left, right);
    }

    private static int helper(int N, int[] heights, int[] dp) {
        if (N<=0) {
            return 0;
        }

        if(dp[N]!=-1) {
//            System.out.println("Reuse: "+(N));
            return dp[N];
        }
        int left , right = Integer.MAX_VALUE;
        left = helper(N-1, heights, dp) + Math.abs(heights[N] - heights[N-1]);

        if(N>1) {
            right = helper(N - 2, heights, dp) + Math.abs(heights[N] - heights[N-2]);
        }

        return dp[N] = Integer.min(left, right);
    }

    public static int frogJumpRecursiveDP(int N, int[] heights) {
        int[] dp = new int[N+1];
        Arrays.fill(dp, -1);
        return helper(N-1, heights, dp);
    }

    public static void main(String[] args) {
        int N = 4;

        int[] heights = new int[]{10, 20, 30, 10};

        System.out.println("Recursive: Min energy: " + frogJumpRecursive(N, heights));
        System.out.println("Recursive DP: Min energy: " + frogJumpRecursiveDP(N, heights));

        N = 6;

        heights = new int[] {30,10,60,10,60,50};

        System.out.println("Recursive: Min energy: " + frogJumpRecursive(N, heights));
        System.out.println("Recursive DP: Min energy: " + frogJumpRecursiveDP(N, heights));
    }
}
