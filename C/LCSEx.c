#include <stdio.h>
#include <string.h>

int dp[100][100];

int maxval(int x, int y) {
    if(x >= y)
        return x;
    return y;
}

int lcsRec(char* str1, char* str2, int n, int m) {
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(str1[n - 1] == str2[m - 1]) {
        return dp[n][m] = 1 + lcsRec(str1,str2,n - 1, m - 1);
    }
    else {
        return dp[n][m] = maxval(lcsRec(str1,str2,n - 1,m), lcsRec(str1,str2,n,m - 1));
    }
}

int lcs(char* str1, char* str2, int n, int m) {

    char lcsStr[10]; 
    int c = 0;
     for(int i = 1; i < n + 1; i++) {
        for(int j = 0; j < m + 1; j++) {
           if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                lcsStr[c] = str1[i - 1];
                c++;
           }
           else {
            dp[i][j] = maxval(dp[i - 1][j],dp[i][j - 1]);
           }
        }
    }
    lcsStr[c] = '\0';
    return dp[n][m];
}

int main()
{
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 0;
        }
    }

    char* str1 = "abedfg";
    char* str2 = "abcdlgh";
    int n = strlen(str1);
    int m = strlen(str2);;


    printf("%d\n", lcs(str1,str2,n,m));
}