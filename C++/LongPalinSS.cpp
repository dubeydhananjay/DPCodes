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
    if (m == 0 || n == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];
    int max = dp[n][m];
    if (str1[n - 1] == str2[m - 1]) {
         dp[n][m] = 1 + lcsRec(str1, str2, n - 1, m - 1);
    }
    else {
         dp[n][m] = maxval(lcsRec(str1, str2, n, m - 1), lcsRec(str1, str2, n - 1, m));
    }

    return maxval(max, dp[n][m]);
}

int main() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 0;
        }
    }

    char* str1 = (char*)"bbbab";
    int n = strlen(str1);
    char str2[n + 1];
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        str2[c] = str1[i];
        c++;
    }
    str2[c] = '\0';
    int m = strlen(str2);

    cout << lcsRec(str1, str2, n, m);
    return 0;
}
