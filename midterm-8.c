// Implement N-Queens problem using backtracking (N will be given in the question).

#include <stdio.h>
#include <stdbool.h>

#define N 10 

void printSolution(int board[N][N], int n);
bool isSafe(int board[N][N], int row, int col, int n);
bool solveNQueensUtil(int board[N][N], int col, int n);

void solveNQueens(int n) {
    int board[N][N] = { {0} };

    if (!solveNQueensUtil(board, 0, n)) {
        printf("Solution does not exist for the given value of N.\n");
        return;
    }

    printSolution(board, n);
}

bool isSafe(int board[N][N], int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N][N], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printSolution(int board[N][N], int n) {
    printf("One possible arrangement of %d queens on a %dx%d chessboard:\n", n, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input! N should be between 1 and %d\n", N);
        return 1;
    }

    solveNQueens(n);

    return 0;
}
