#include <iostream>
#include <cstring>
using namespace std;

int dp[100][100];

int maxval(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

int lcsRec(char* str1, char* str2, int n, int m) {
    if (n == 0 || m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];
    int max = dp[n][m];
    if (str1[n - 1] == str2[m - 1]) {
         dp[n][m] = 1 + lcsRec(str1, str2, n - 1, m - 1);
    }
    else {
         dp[n][m] = 0;
    }

    return maxval(max, dp[n][m]);
}

int lcs(char* str1, char* str2, int n, int m) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    int max = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (max <= dp[i][j])
                max = dp[i][j];
        }
    }

    return max;
}

int main() {
    memset(dp, -1, sizeof(dp));

    char* str1 = (char*)"abelfgh";
    char* str2 = (char*)"abcdfgh";
    int n = strlen(str1);
    int m = strlen(str2);

    cout << lcs(str1, str2, n, m);

    return 0;
}
