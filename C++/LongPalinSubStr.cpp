#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int dp[100][100];

char* lcs(char* str1, char* str2, int m, int n) {
    char* str = (char*)malloc(1000 * sizeof(char));
    int c = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                str[c] = str1[i - 1];
                c++;
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    str[c] = '\0';
    return str;
}

int main() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 0;
        }
    }

    char* str1 = (char*)"babad";
    int n = strlen(str1);
    char str2[n + 1];
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        str2[c] = str1[i];
        c++;
    }
    str2[c] = '\0';
    int m = strlen(str2);
    printf("%s", lcs(str1, str2, n, m));

    return 0;
}
