package dp;

public class Knapsack {

    private static int knapsack(int[] wts, int[] prices, int N, int W) {
        if(N==0 || W<=0) {
            return 0;
        }
        int inc = 0;
        if(W-wts[N-1]>=0) {
            inc = prices[N-1] + knapsack(wts, prices, N-1, W-wts[N-1]);
        }
        int exc = knapsack(wts, prices, N-1, W);

        return Integer.max(inc, exc);
    }

    public static void main(String[] args) {
        int N = 4;
        int W = 11;

        int[] wts = {2, 7, 3, 4};
        int[] prices = {5, 20, 20, 10};

        System.out.println("Knapsack: " + knapsack(wts, prices, N, W));
    }
}
