#include <stdio.h>

int max(int a, int b, int c) {
    return (a > b) ? (a>c)?a:c : (b>c)?b:c;
}

int max_crossing_subarray(int arr[], int low, int mid, int high) {
    int left_sum = -2147483647;
    int sum = 0;
    int i;

    for (i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = -2147483647;
    sum = 0;

    for (i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int max_subarray(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return max(max_subarray(arr, low, mid),
               max_subarray(arr, mid + 1, high),
               max_crossing_subarray(arr, low, mid, high));
}	 	  	 	  	   	 		  	     	  	 	

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = max_subarray(arr, 0, n - 1);

    printf("%d", result);

    return 0;
}
