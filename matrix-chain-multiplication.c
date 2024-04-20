#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int dimensions[], int n) {
   
    int dp[n][n];

    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    int dimensions[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &dimensions[i]);
    }
    printf("%d\n", matrixChainMultiplication(dimensions, n));

    return 0;
}	 	  	 	  	   	 		  	     	  	 	
