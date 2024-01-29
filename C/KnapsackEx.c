#include <stdio.h>

int dp[5][8];

int maxval(int x, int y) {
    if(x >= y)
        return x;
    return y;
}

int knapsack(int* wtArr, int* wtVal, int W, int n) {
    if(W <= 0 || n <= 0)
        return 0;
    if(dp[n][W] != -1) 
        return dp[n][W];

    if(wtArr[n - 1] <= W) {
        return dp[n][W] = maxval(wtVal[n - 1] + knapsack(wtArr,wtVal, W - wtArr[n - 1], n - 1), knapsack(wtArr,wtVal, W, n - 1));
    }
    else {
         return dp[n][W] = knapsack(wtArr,wtVal, W, n - 1);
    }
}

int main()
{
   int wtArr[] = {1,3,4,5};
   int wtVal[] = {1,4,5,7};
   int W = 7;
   int n = 4;
   for(int i = 0; i < 5; i++) 
   {
    for(int j = 0; j < 8; j++) 
    {
        dp[i][j] = -1;
    }
   }

   printf("Max profit: " + knapsack(wtArr,wtVal,W,n));
    return 0;
}