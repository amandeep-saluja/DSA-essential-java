package dp;

import java.util.Arrays;

public class ClimbingStairs {

    private static int helper(int N, int[] dp) {
        if(N==0 || N==1) {
            return 1;
        }

        int left , right ;

        if(dp[N-1]!=-1) {
            left = dp[N-1];
        }else {
            left = dp[N-1] = helper(N-1, dp);
        }

        if(dp[N-2]!=-1) {
            right = dp[N-2];
        }else {
            right = dp[N-2] = helper(N-2, dp);
        }

        return left + right;
    }
    public static int wayToReachN(int N) {
        int[] dp = new int[N+1];
        Arrays.fill(dp, -1);
        return helper(N, dp);
    }

    public static void main(String[] args) {
        int N = 4;

        System.out.println("Ways to climb "+ N +" stairs: "+wayToReachN(N));
    }
}
