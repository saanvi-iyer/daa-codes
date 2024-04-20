#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    double ratio;
} Vegetable;

void swap(Vegetable *a, Vegetable *b) {
    Vegetable temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_ratio(Vegetable arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double max_profit(Vegetable arr[], int n, int capacity) {
    sort_by_ratio(arr, n);

    double total_profit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break;
        }

        if (arr[i].weight <= capacity) {
            total_profit += arr[i].profit;
            capacity -= arr[i].weight;
        } else {	 	  	 	  	   	 		  	     	  	 	
            total_profit += (arr[i].ratio * capacity);
            break;
        }
    }

    return total_profit;
}

int main() {
    int n;
    scanf("%d", &n);

    Vegetable vegetables[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vegetables[i].weight);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vegetables[i].profit);
        vegetables[i].ratio = (double)vegetables[i].profit / vegetables[i].weight;
    }

    int capacity;
    
    scanf("%d", &capacity);

    double result = max_profit(vegetables, n, capacity);

    printf("%.2lf", result);

    return 0;
}
	 	  	 	  	   	 		  	     	  	 	
