#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointList;

// Function to calculate the orientation of an ordered triplet (p, q, r).
// The function returns positive if p-q-r are clockwise, negative if counterclockwise,
// and zero if collinear.
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0)? 1: 2; // clock or counterclockwise
}

// Function to find the leftmost point
int leftMost(Point points[], int n) {
    int leftMost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftMost].x)
            leftMost = i;
    return leftMost;
}

// Function to find the next point of the convex hull
int nextToTop(Point stack[], int top) {
    return (top > 0)? top - 1: top;
}

// Function to implement Jarvis March algorithm
void jarvisMarch(Point points[], int n) {
    // Find the leftmost point
    int l = leftMost(points, n);

    // Create an empty stack and push the leftmost point to it
    Point stack[n];
    int top = 0;
    stack[top] = points[l];

    // Start from the leftmost point, keep moving counterclockwise until the start point is reached again
    int p = l, q;
    do {
        // Find the point with the smallest angle formed with p
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than q, then update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Add the point to the stack
        top++;
        stack[top] = points[q];

        // Move to the next point
        p = q;
    } while (p != l); // While we don't come to the first point

    // Print the points on the convex hull
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("(%d,%d)", &points[i].x, &points[i].y);
    }

    jarvisMarch(points, n);

    return 0;
}
