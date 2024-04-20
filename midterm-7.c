// Consider two strings, str1 and str2.  Given that each insertion, deletion and edit operation costs one unit.
// Write and execute a program to print the minimum edit distance and the minimum cost edit sequence 
// that transforms str1 into str2 by using a suitable algorithm design technique.
// To simplify things, assume that length(str1) >= length(str2) so that insert operation will not be applicable

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

void printEditSequence(char str1[], char str2[], int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);

    int i = m, j = n;
    printf("Minimum Cost Edit Sequence:\n");
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("Edit %c -> %c\n", str1[i - 1], str2[j - 1]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j] + 1) {
            printf("Delete %c\n", str1[i - 1]);
            i--;
        } else if (dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert %c\n", str2[j - 1]);
            j--;
        }
    }

    while (i > 0) {
        printf("Delete %c\n", str1[i - 1]);
        i--;
    }

    while (j > 0) {
        printf("Insert %c\n", str2[j - 1]);
        j--;
    }
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    printEditSequence(str1, str2, m, n);
    
    return 0;
}
