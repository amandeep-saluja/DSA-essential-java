package dp;

public class FrogJump {

    public static int frogJump(int N, int[] heights) {
        if (N == 0) {
            return 0;
        }
        if(N==1) {
            return heights[0];
        }

        int left = frogJump(N - 1, heights);
        System.out.println("left->"+left);
        int right = frogJump(N - 2, heights);
        System.out.println("right->"+right);

        return Integer.min(left, right);
    }

    public static void main(String[] args) {
        int N = 4;

        int[] heights = new int[]{10, 20, 30, 10};

        System.out.println("Min energy: " + frogJump(N, heights));
    }
}
