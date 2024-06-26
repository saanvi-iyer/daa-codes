#include <stdio.h>

// Maze dimensions
#define N 4

// Function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

// Function to check if x, y is valid index for N*N maze
int isSafe(int maze[N][N], int x, int y) {
    // if (x, y outside maze) return false
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve Maze problem using backtracking
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == 1) {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        // Move forward in x direction
        if (solveMazeUtil(maze, x + 1, y, sol) == 1)
            return 1;

        // If moving in x direction doesn't give solution then move down in y direction
        if (solveMazeUtil(maze, x, y + 1, sol) == 1)
            return 1;

        // If none of the above movements work then BACKTRACK: unmark x, y as part of solution path
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

// Function to solve the Maze problem
void solveMaze(int maze[N][N]) {
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("Solution doesn't exist");
        return;
    }

    printSolution(sol);
}

int main() {
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}
