#include <stdio.h>

#define MAX 100

int subset[MAX]; 
int weights[MAX]; 
int n, target; 

void printSubset() {
    for (int i = 0; i < n; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void findSubsets(int idx, int sum) {
    if (sum == target) {
        printSubset();
        return;
    }
    if (sum > target || idx == n) {
        return;
    }

    subset[idx] = 1;
    findSubsets(idx + 1, sum + weights[idx]);

    subset[idx] = 0;
    findSubsets(idx + 1, sum);
}

int main() {
    scanf("%d", &n);
    scanf("%d", &target);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    findSubsets(0, 0);

    return 0;
}
