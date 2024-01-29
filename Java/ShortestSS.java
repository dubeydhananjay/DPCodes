public class ShortestSubsequence {

    static int[][] dp = new int[100][100];

    static int maxval(int x, int y) {
        if (x >= y)
            return x;
        return y;
    }

    static int lcsRec(String str1, String str2, int m, int n) {
        if (m == 0 || n == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (str1.charAt(m - 1) == str2.charAt(n - 1))
            return dp[m][n] = 1 + lcsRec(str1, str2, m - 1, n - 1);
        else
            return dp[m][n] = maxval(lcsRec(str1, str2, m - 1, n), lcsRec(str1, str2, m, n - 1));
    }

    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                dp[i][j] = -1;
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }

        String str1 = "geek";
        String str2 = "eke";
        int m = str1.length();
        int n = str2.length();

        System.out.println((m + n) - lcsRec(str1, str2, m, n));
    }
}
