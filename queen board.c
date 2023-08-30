#include <stdio.h>
#include <stdbool.h>

#define N 10

void printBoard(int board[N][N], int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col, int n) {
	int i,j;

    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int col, int n) {
    if (col >= n) {
        printBoard(board, n);
        return true;
    }
    int i;
    bool res = false;
    for (i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, n) || res;
            board[i][col] = 0; 
        }
    }
    return res;
}

void solveNQueens(int n) {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0, n)) {
        printf("No solution exists.\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    solveNQueens(n);

    return 0;
}

