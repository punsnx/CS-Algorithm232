// good but time limit
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int r, c, Q, R, B;

int walk(int **board, int i, int j, int piece) {
    for (int u = 0; u < r; u++) {
        for (int v = 0; v < c; v++) {
            if (board[u][v] != 0) {
                int p = board[u][v];
                if (u == i || v == j) {
                    if ((piece == 1 || piece == 2) || (p == 1 || p == 2))
                        return 0;
                }
                if (abs(u - i) == abs(v - j)) {
                    if ((piece == 1 || piece == 3) || (p == 1 || p == 3))
                        return 0;
                }
            }
        }
    }
    return 1;
}

long long calculate(int **board, int idx, int q, int rPiece, int b) {
    if (q == 0 && rPiece == 0 && b == 0)
        return 1;
    if (idx >= r * c)
        return 0;
    
    long long ways = 0;
    ways += calculate(board, idx + 1, q, rPiece, b);
    
    int i = idx / c;
    int j = idx % c;
    
    if (q > 0 && walk(board, i, j, 1)) {
        board[i][j] = 1;
        ways += calculate(board, idx + 1, q - 1, rPiece, b);
        board[i][j] = 0;
    }
    

    if (rPiece > 0 && walk(board, i, j, 2)) {
        board[i][j] = 2;
        ways += calculate(board, idx + 1, q, rPiece - 1, b);
        board[i][j] = 0; 
    }
    

    if (b > 0 && walk(board, i, j, 3)) {
        board[i][j] = 3;
        ways += calculate(board, idx + 1, q, rPiece, b - 1);
        board[i][j] = 0; 
    }
    
    return ways;
}

int main() {
    scanf("%d %d", &r, &c);
    scanf("%d %d %d", &Q, &R, &B);
    
    int **board = malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        board[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
            board[i][j] = 0;
    }
    
    long long ans = calculate(board, 0, Q, R, B);
    printf("%lld\n", ans);

    return 0;
}
