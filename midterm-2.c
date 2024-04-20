// Design and implement an algorithm that will find the top and the least scores of students from an online Quiz, 
// using divide and conquer strategy. Note: The scores are stored in an array.

#include <stdio.h>

// Function to find the top and least scores using divide and conquer
void findTopAndLeast(int scores[], int start, int end, int *top, int *least) {
    if (start == end) {
        // Base case: If there's only one element
        *top = scores[start];
        *least = scores[start];
    } else if (end - start == 1) {
        // Base case: If there are two elements
        *top = (scores[start] > scores[end]) ? scores[start] : scores[end];
        *least = (scores[start] < scores[end]) ? scores[start] : scores[end];
    } else {
        // Recursive case: Divide the array into two halves
        int mid = (start + end) / 2;
        int top1, top2, least1, least2;
        // Recursively find the top and least scores in each half
        findTopAndLeast(scores, start, mid, &top1, &least1);
        findTopAndLeast(scores, mid + 1, end, &top2, &least2);
        // Merge the results
        *top = (top1 > top2) ? top1 : top2;
        *least = (least1 < least2) ? least1 : least2;
    }
}

int main() {
    int scores[] = {89, 78, 92, 56, 71, 85, 62, 99, 77}; // Sample scores
    int num_scores = sizeof(scores) / sizeof(scores[0]);

    int top_score, least_score;

    // Find the top and least scores
    findTopAndLeast(scores, 0, num_scores - 1, &top_score, &least_score);

    // Print the results
    printf("Top score: %d\n", top_score);
    printf("Least score: %d\n", least_score);

    return 0;
}
