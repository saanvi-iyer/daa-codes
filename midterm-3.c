// Design a solution for an Airline Customer on what to leave behind 
// and what to carry based on cabin baggage weight limits. 
// The Customer has to pack as many items as the limit allows while 
// maximizing the total worth. The data needed will be shared along with the question.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    char name[50];
    double weight;
    double value;
} Item;

// Function to compare two items based on their value per unit weight
int compareItems(const void *a, const void *b) {
    double ratio_a = ((Item *)a)->value / ((Item *)a)->weight;
    double ratio_b = ((Item *)b)->value / ((Item *)b)->weight;
    if (ratio_a < ratio_b)
        return 1;
    else if (ratio_a > ratio_b)
        return -1;
    else
        return 0;
}

// Function to select items to carry based on weight limit
void selectItems(Item items[], int n, double weight_limit) {
    // Sort items based on value per unit weight
    qsort(items, n, sizeof(Item), compareItems);

    double total_weight = 0.0;
    double total_value = 0.0;

    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= weight_limit) {
            printf("%s (Weight: %.2f, Value: %.2f)\n", items[i].name, items[i].weight, items[i].value);
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            printf("Cannot carry %s (Weight: %.2f, Value: %.2f) due to weight limit\n", items[i].name, items[i].weight, items[i].value);
        }
    }

    printf("Total weight carried: %.2f\n", total_weight);
    printf("Total value carried: %.2f\n", total_value);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    // Input items data
    for (int i = 0; i < n; i++) {
        printf("Enter name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter weight of item %d: ", i + 1);
        scanf("%lf", &items[i].weight);
        printf("Enter value of item %d: ", i + 1);
        scanf("%lf", &items[i].value);
    }

    double weight_limit;
    printf("Enter cabin baggage weight limit: ");
    scanf("%lf", &weight_limit);

    // Select items to carry based on weight limit
    selectItems(items, n, weight_limit);

    free(items);

    return 0;
}
