#include <iostream>
#include <cstring>
using namespace std;

int dp[100][100];

int maxval(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

int lcsRec(char* str1, char* str2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (str1[m - 1] == str2[n - 1])
        return dp[m][n] = 1 + lcsRec(str1, str2, m - 1, n - 1);

    return dp[m][n] = maxval(lcsRec(str1, str2, m - 1, n), lcsRec(str1, str2, m, n - 1));
}

int main() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 0;
        }
    }

    char* str1 = (char*)"agbkcba";
    int m = strlen(str1);
    char str2[m + 1];
    int c = 0;
    for (int i = m - 1; i >= 0; i--) {
        str2[c] = str1[i];
        c++;
    }
    str2[c] = '\0';
    int n = strlen(str2);

    int del = m - lcsRec(str1, str2, m, n);
    cout << del;

    return 0;
}
