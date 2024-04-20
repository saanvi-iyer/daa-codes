#include <stdio.h>

// Structure to represent a point in 2D space
struct Point {
    int x, y;
};

// Function to find the orientation of three points
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;     // Collinear
    return (val > 0) ? 1 : 2;   // Clockwise or counterclockwise
}

// Function to find the convex hull of a set of points using Jarvis March algorithm
void convexHull(struct Point points[], int n) {
    // If there are less than 3 points, convex hull is not possible
    if (n < 3) return;

    // Initialize an array to store the convex hull
    struct Point hull[n];
    int hullIndex = 0;

    // Find the leftmost point
    int leftMost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftMost].x)
            leftMost = i;
    }

    int p = leftMost, q;
    do {
        // Add the current point to the convex hull
        hull[hullIndex++] = points[p];

        // Find the next point on the hull in counterclockwise direction
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than current q, update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != leftMost);

    // Print the points on the convex hull
    for (int i = 0; i < hullIndex; i++) {
        printf("(%d,%d)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    int n;
    printf("Enter the total number of turns: ");
    scanf("%d", &n);

    struct Point points[n];
    printf("Enter the points representing turns as ordered pairs (x-coordinate, y-coordinate):\n");
    for (int i = 0; i < n; i++) {
        scanf("(%d,%d)", &points[i].x, &points[i].y);
    }

    // Find and print the convex hull
    convexHull(points, n);

    return 0;
}
