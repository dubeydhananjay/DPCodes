#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int dp[100][100];

int maxval(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

char* lcs(char* s1, char* s2, int m, int n) {
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = maxval(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    char* str = (char*)malloc((m + n + 1) * sizeof(char));
    int c = 0;
    int x = m;
    int y = n;
    while (x > 0 && y > 0) {
        if (s1[x - 1] == s2[y - 1]) {
            str[c] = s1[x - 1];
            x--;
            y--;
        }
        else if (dp[x][y - 1] > dp[x - 1][y]) {
            str[c] = s2[y - 1];
            y--;
        }
        else {
            str[c] = s1[x - 1];
            x--;
        }
        c++;
    }
    while (x > 0) {
        str[c] = s1[x - 1];
        x--;
        c++;
    }
    while (y > 0) {
        str[c] = s2[y - 1];
        y--;
        c++;
    }
    str[c] = '\0';
    c = 0;
    char* revStr = (char*)malloc((m + n) * sizeof(char));
    for (int i = strlen(str) - 1; i >= 0; i--) {
        revStr[c] = str[i];
        c++;
    }
    revStr[c] = '\0';
    return revStr;
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

    char* s1 = (char*)"HELLO";
    char* s2 = (char*)"GEEK";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("%s", lcs(s1, s2, m, n));
    return 0;
}
