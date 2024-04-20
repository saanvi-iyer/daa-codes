//Assume you have an unparenthesized arithmetic expression. 
//You can change the value of expression by parenthesizing at different positions. 
//To keep it simple, assume that the expression comprises only + and * operators 
//and parenthesis occurs only immediately before/after operands and not before/after operators. 
//Write and execute a program that can output the maximum possible value that can be obtained 
//by evaluating the expression by different parenthesizations.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to perform arithmetic operation
int performOperation(int a, int b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '*':
            return a * b;
        default:
            return INT_MIN; // Error case
    }
}

// Recursive function to evaluate expression and find maximum value
int findMaxValue(char* exp, int start, int end) {
    // Base case: single operand
    if (start == end) {
        return exp[start] - '0'; // Convert character to integer
    }

    int maxVal = INT_MIN;

    // Try all possible parenthesizations
    for (int i = start + 1; i < end; i += 2) {
        int left = findMaxValue(exp, start, i - 1);
        int right = findMaxValue(exp, i + 1, end);
        int result = performOperation(left, right, exp[i]);
        if (result > maxVal) {
            maxVal = result;
        }
    }

    return maxVal;
}

// Function to find maximum value by evaluating expression
int maxExpressionValue(char* exp) {
    int len = 0;
    while (exp[len] != '\0') {
        len++;
    }
    return findMaxValue(exp, 0, len - 1);
}

int main() {
    char expression[] = "1+2*3+4*5";
    int maxValue = maxExpressionValue(expression);
    printf("Maximum value possible: %d\n", maxValue);
    return 0;
}
