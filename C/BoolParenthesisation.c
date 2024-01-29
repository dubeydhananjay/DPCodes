#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[100][100];

int solve(char* s, int i, int j, bool isTrue) {
    if(i > j) return 0;

    if(i == j) {
        if(isTrue) return s[i] == 'T' ? 1 : 0;
        else return s[i] = 'F' ? 1 : 0;
    }
    int ans = 0;
    for(int k = k + 1; k < j; k += 2) {
        int lF = solve(s,i,k - 1,false);
        int lT = solve(s,i,k - 1,true);
        int rF = solve(s,k + 1,j,false);
        int rT = solve(s,k + 1,j,true);
        if(s[k] == '&') {
            if(isTrue == true) {
                ans += (lT * rT);
            }
            else {
                ans += (lT * rF) + (lF * rF) + (lF * rT);
            }
        }
        else if(s[k] == '|') {
            if(isTrue == true) {
                ans += (lT * rF) + (lT * rT) + (lF * rT);
            }
            else {
                ans += (lF * rF);
            }
        }
        else {
            if(isTrue == true) {
                ans += (lF * rT) + (lT * rF);
            }
            else {
                ans += (lF * rF) + (lT * rT);
            }
        }
    }
}

int main() {
    char* s = "T^F&T";
    printf("%d", solve(s,0,strlen(s) - 1,true));
    return 0;
}