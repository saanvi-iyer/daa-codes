#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Function to calculate the number of digits in a given number
int numDigits(int64_t num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to implement Karatsuba multiplication
int64_t karatsuba(int64_t x, int64_t y) {
    // Base case: If either x or y is a single-digit number, perform regular multiplication
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Calculate the number of digits in the two numbers
    int m = fmin(numDigits(x), numDigits(y));
    int m2 = m / 2;

    // Split the two numbers into high and low parts
    int64_t high1 = x / pow(10, m2);
    int64_t low1 = x % (int64_t)pow(10, m2);
    int64_t high2 = y / pow(10, m2);
    int64_t low2 = y % (int64_t)pow(10, m2);

    // Recursively calculate three products required by the Karatsuba algorithm
    int64_t z0 = karatsuba(low1, low2);
    int64_t z1 = karatsuba((low1 + high1), (low2 + high2));
    int64_t z2 = karatsuba(high1, high2);

    // Combine the results using the Karatsuba formula
    return (z2 * (int64_t)pow(10, 2 * m2)) + ((z1 - z2 - z0) * (int64_t)pow(10, m2)) + z0;
}	 	  	 	  	   	 		  	     	  	 	

int main() {
    int64_t x, y;

    scanf("%ld", &x);

    scanf("%ld", &y);

    int64_t result = karatsuba(x, y);

    printf("%ld\n", result);

    return 0;
}
