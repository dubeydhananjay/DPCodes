#include <iostream>
using namespace std;

int dp[101][10001];

int maxVal(int x, int y) {
    if (x >= 0) return x;
    return y;
}

int minVal(int x, int y) {
    if (x <= 0) return x;
    return y;
}

int solve(int e, int f) {
    if (dp[e][f] != -1) return dp[e][f];

    if (f <= 1) return dp[e][f] = f;

    if (e == 1) return dp[e][f] = f;
    int mn = INT32_MAX;
    int left = 0;
    int right = f;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int low = 0;
        if (dp[e - 1][mid - 1] != -1) {
            low = dp[e - 1][mid - 1];
        } else {
            low = solve(e - 1, mid - 1);
            dp[e - 1][mid - 1] = low;
        }
        int high = 0;
        if (dp[e][f - mid] != -1) {
            high = dp[e][f - mid];
        } else {
            high = solve(e, f - mid);
            dp[e][f - mid] = high;
        }

        int ans = 1 + maxVal(low, high);
        mn = minVal(mn, ans);
        if (low < high)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return dp[e][f] = mn;
}

int main() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 10001; j++) {
            dp[i][j] = -1;
        }
    }
    int e = 2;
    int f = 6;
    cout << solve(e, f);

    return 0;
}
