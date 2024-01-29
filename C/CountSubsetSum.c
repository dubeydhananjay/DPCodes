#include <stdio.h>

int dp[100][100];
int countSubsetSum(int arr[], int n, int sum) {

    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;

    if(dp[n][sum] != -1) return dp[n][sum];

    if(arr[n - 1] > sum) {
        return dp[n][sum] = countSubsetSum(arr, n - 1, sum);
    }
    return dp[n][sum] = countSubsetSum(arr, n - 1, sum - arr[n - 1]) + countSubsetSum(arr, n - 1, sum);
    

}

int main() {

    int arr[] = {2,3,5,6,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    printf("%d", countSubsetSum(arr,n,sum));
    return 0;
}