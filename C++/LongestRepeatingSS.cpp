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

    if (str1[n - 1] == str2[m - 1] && m != n) {
        return dp[n][m] = 1 + lcsRec(str1, str2, n - 1, m - 1);
    }
    else {
        return dp[n][m] = maxval(lcsRec(str1, str2, n - 1, m), lcsRec(str1, str2, n, m - 1));
    }
}

int lcs(char* str1, char* str2, int n, int m) {
    char lcsStr[10];
    int c = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                lcsStr[c] = str1[i - 1];
                c++;
            }
            else {
                dp[i][j] = maxval(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    lcsStr[c] = '\0';
    cout << lcsStr << endl;
    return dp[n][m];
}

int main() {
    memset(dp, -1, sizeof(dp));

    char* str1 = (char*)"AABEBC";
    int n = strlen(str1);

    cout << lcsRec(str1, str1, n, n);

    return 0;
}
