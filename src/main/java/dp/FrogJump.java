package dp;

public class FrogJump {

    public static int frogJump(int N, int[] heights) {
        if (N<=1) {
            return 0;
        }
//        if(N==1 || N==2) {
//            return heights[N-1];
//        }

        int left = frogJump(N - 1, heights) + Math.abs(heights[N-1] - heights[N-2]);

        int right = Integer.MAX_VALUE;

        if(N>2) {
            right = frogJump(N - 2, heights) + Math.abs(heights[N-1] - heights[N-3]);
        }


        return Integer.min(left, right);
    }

    public static void main(String[] args) {
        int N = 4;

        int[] heights = new int[]{10, 20, 30, 10};

        System.out.println("Min energy: " + frogJump(N, heights));
    }
}
