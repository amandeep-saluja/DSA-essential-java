package dp;

import java.util.Scanner;

public class Fibonacci {

    public static int fibonacciLoop(int N) {

        int last = 1, secondLast = 0;
        int current = 0;

        for(int term=2; term<=N; term++) {
            current = last + secondLast;
            secondLast = last;
            last = current;
        }

        return current;
    }

    private static int fibonacciLoopDP(int N) {
        int[] dp = new int[N+1];
        dp[1] = 1;

        for(int term=2; term<=N; term++) {
            dp[term] = dp[term-1] + dp[term-2];
        }

        return dp[N];
    }

    private  static int fibonacciRecursive(int N) {
        if(N==0 || N==1) {
            return N;
        }

        return fibonacciRecursive(N-1) + fibonacciRecursive(N-2);
    }

    private static int helper(int N, int[] dp) {
        if(N==0 || N==1) {
            dp[0] = 0;
            dp[1] = 1;
            return dp[N];
        }
        dp[N] = helper(N-1, dp) + helper(N-2, dp);
        return dp[N];
    }

    private static int fibonacciRecursiveDP(int N) {
        int[] dp = new int[N+1];
        return helper(N, dp);
    }

    public static void main(String[] args) {
        int N;

        Scanner kb = new Scanner(System.in);
        System.out.println("Enter the number you want to fetch");
        N = kb.nextInt();

        System.out.println("Number is "+fibonacciLoop(N));
        System.out.println("Number is "+fibonacciLoopDP(N));
        System.out.println("Number is "+fibonacciRecursive(N));
        System.out.println("Number is "+fibonacciRecursiveDP(N));
    }
}
