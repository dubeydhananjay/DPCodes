#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int arr[], int n, int sum) {

    if(sum == 0)
        return true;
    if(n == 0)
        return false;

    if(arr[n - 1] > sum) {
        return isSubsetSum(arr, n - 1, sum);
    }

    return  isSubsetSum(arr, n - 1, sum - arr[n - 1]) ||  isSubsetSum(arr, n - 1, sum);   

}

bool isEqualSumPartition(int arr[], int n, int sum) {

    if(sum % 2 != 0) return false;

    return isSubsetSum(arr,n,sum/2);
}

int main() {

    int arr[] = {1,5,12,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if(isEqualSumPartition(arr, n, sum) == true) {
        printf("TRUE");
    }
    else {
        printf("FALSE");
    }
    return 0;

}