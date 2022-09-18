package dp;

import java.util.Arrays;

public class Knapsack {

    // Top to bottom of tree -> recursive
    private static int knapsackRecursive(int[] wts, int[] prices, int N, int W) {
        if (N == 0 || W <= 0) {
            return 0;
        }
        int inc = 0;
        if (W - wts[N - 1] >= 0) {
            inc = prices[N - 1] + knapsackRecursive(wts, prices, N - 1, W - wts[N - 1]);
        }
        int exc = knapsackRecursive(wts, prices, N - 1, W);

        return Integer.max(inc, exc);
    }

    private static int knapsackRecursiveDP(int[] wts, int[] prices, int N, int W) {
        int[][] dp = new int[N + 1][W + 1];
        Arrays.stream(dp).forEach(x -> Arrays.fill(x, -1));
        return helper(wts, prices, N, W, dp);
    }

    private static int helper(int[] wts, int[] prices, int N, int W, int[][] dp) {
        if (N == 0 || W == 0) {
//            if (wts[0] <= W) return prices[0];
            return 0;
        }
//        System.out.println("DP of N: " + N + " W: " + W + " dp: " + dp[N][W]);
        if (dp[N][W] != -1) {
//            System.out.println("revisited for N: " + N + " W: " + W + " dp: " + dp[N][W]);
            return dp[N][W];
        }
        int inc = 0;
        // check whether wts of current item is less than or equal to current bag capacity
        if (wts[N - 1] <= W) {
            inc = prices[N - 1] + helper(wts, prices, N - 1, W - wts[N - 1], dp);
        }
        int exc = helper(wts, prices, N-1, W, dp);

        dp[N][W] = Integer.max(inc, exc);

        return dp[N][W];
    }

    private static int knapsackLoopDP(int[] wts, int[] prices, int N, int W) {
        /*
            N -> total number of items
            W -> total capacity of bag
            wts -> weights array
            prices -> prices of items corresponding to weight
        */
        int[][] dp = new int[N + 1][W + 1];

        for (int n = 1; n <= N; n++) {
            // n -> no of items
            // w -> current capacity of bag
            for (int w = 1; w <= W; w++) {
                int inc=0, exc;
                // either we can include current item or exclude it
                // if we include current item, then current weight
                // should be less than or equal to current capacity of bag
                // nth item will be present at n-1 th index of weights array
                if (wts[n - 1] <= w) {
                    // inc = sum of current item price + sub problem of weight minus current capacity of bag
                    // dp[n-1][w - wts[n-1]] -> previous row or previous item with weight difference (current capacity - current item weight)
                    inc = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
                }
                exc = dp[n - 1][w];

                dp[n][w] = Integer.max(inc, exc);
            }
        }

        return dp[N][W];
    }

    public static void main(String[] args) {
        int N = 4;
        int W = 11;

        int[] wts = {2, 7, 3, 4};
        int[] prices = {5, 20, 20, 10};

        System.out.println("Knapsack recursive: " + knapsackRecursive(wts, prices, N, W));

        System.out.println("Knapsack bottom up dp: " + knapsackLoopDP(wts, prices, N, W));

        System.out.println("Knapsack top to bottom dp: " + knapsackRecursiveDP(wts, prices, N, W));
    }
}
