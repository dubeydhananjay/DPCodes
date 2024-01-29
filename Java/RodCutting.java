public class RodCutting {

    static int[][] dp = new int[100][100];

    static int maxval(int x, int y) {
        if (x >= y)
            return x;
        return y;
    }

    static int rodCutting(int[] wtArr, int[] wtVal, int W, int n) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wtArr[i - 1] <= j) {
                    dp[i][j] = maxval(wtVal[i - 1] + dp[i][j - wtArr[i - 1]], dp[i - 1][j]);
                } else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][W];
    }

    static int rodCuttingRec(int[] wtArr, int[] wtVal, int W, int n) {
        if (W <= 0 || n <= 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wtArr[n - 1] > W)
            return dp[n][W] = rodCuttingRec(wtArr, wtVal, W, n - 1);

        return dp[n][W] = maxval(wtVal[n - 1] + rodCutting(wtArr, wtVal, W - wtArr[n - 1], n),
                rodCutting(wtArr, wtVal, W, n - 1));
    }

    public static void main(String[] args) {
        int[] wtArr = {1, 2, 3, 4, 5, 6, 7, 8};
        int[] wtVal = {1, 5, 8, 9, 10, 17, 17, 20};
        int n = wtArr.length;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = -1;
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }
        System.out.println(rodCuttingRec(wtArr, wtVal, n, n));
    }
}
