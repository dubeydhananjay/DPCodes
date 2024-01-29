#include <stdio.h> 

/*
   1 -> Sum of first subset(S1) - Sum of second subset(S2) = Given difference
   2 -> Sum of first subset(S1) + Sum of second subset(S2) = Sum of given array
    Adding above 2 equations
    2S1 = Given diff + Sum of array i.e S1 = (Given diff + Sum of array)/2
*/


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

    int arr[] = {1,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff = 1;
    int sum = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int sumForSubset = (diff + sum)/2;
    printf("%d", countSubsetSum(arr,n,sumForSubset));
    return 0;
}
