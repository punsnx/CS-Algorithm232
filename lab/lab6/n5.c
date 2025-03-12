// good but time limit
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int row, col, Q, R, B;
char **board;// 0 empty 1 queen 2 rook 3 bishop

int walk(int i, int j, int piece) {
    int u, v;
    // horizontal
    for (v = 0; v < col; v++) {
        if (v == j)
            continue;
        if (board[i][v] != 0) {
            int p = board[i][v];
            if ((piece == 1 || piece == 2) || (p == 1 || p == 2))
                return 0;
        }
    }
    // vertical
    for (u = 0; u < row; u++) {
        if (u == i)
            continue;
        if (board[u][j] != 0) {
            int p = board[u][j];
            if ((piece == 1 || piece == 2) || (p == 1 || p == 2))
                return 0;
        }
    }
    // Up-left
    u = i - 1, v = j - 1;
    while (u >= 0 && v >= 0) {
        if (board[u][v] != 0) {
            int p = board[u][v];
            if ((piece == 1 || piece == 3) || (p == 1 || p == 3))
                return 0;
        }
        u--; v--;
    }
    // Down-right
    u = i + 1, v = j + 1;
    while (u < row && v < col) {
        if (board[u][v] != 0) {
            int p = board[u][v];
            if ((piece == 1 || piece == 3) || (p == 1 || p == 3))
                return 0;
        }
        u++; v++;
    }
    // Up-right
    u = i - 1, v = j + 1;
    while (u >= 0 && v < col) {
        if (board[u][v] != 0) {
            int p = board[u][v];
            if ((piece == 1 || piece == 3) || (p == 1 || p == 3))
                return 0;
        }
        u--; v++;
    }
    // Down-left
    u = i + 1, v = j - 1;
    while (u < row && v >= 0) {
        if (board[u][v] != 0) {
            int p = board[u][v];
            if ((piece == 1 || piece == 3) || (p == 1 || p == 3))
                return 0;
        }
        u++; v--;
    }
    return 1;

}int queenWalk(char sr, char sc) {   
    return walk(sr,sc,1);
}
int rookWalk(char sr,char sc){
    return walk(sr,sc,2);
}
int bishopWalk(char sr,char sc){
    return walk(sr,sc,3);
}

long cal(char index, char q,char r,char b) {
    if(q == Q && r == R && b == B)return 1;
    if (index >= row * col)return 0;
    long ways = 0;
    char i = index / col, j = index % col;
    ways += cal(index + 1, q,r,b);
    if(q < Q && !board[i][j] && queenWalk(i,j)) {
        board[i][j] = 1;
        ways += cal(index + 1, q + 1,r,b);
        board[i][j] = 0;
    }
    if(r < R && !board[i][j] && rookWalk(i,j)) {
        board[i][j] = 2;
        ways += cal(index + 1, q,r + 1,b);
        board[i][j] = 0;
    }
    if(b < B && !board[i][j] && bishopWalk(i,j)) {
        board[i][j] = 3;
        ways += cal(index + 1, q,r,b + 1);
        board[i][j] = 0;
    }

    return ways;

    
}

int main() {
    scanf("%d %d", &row, &col);
    scanf("%d %d %d", &Q, &R, &B);
    
    board = (char**)malloc(row * sizeof(char*));
    for(int i = 0; i < row; i++) {
        board[i] = (char*)calloc(col, sizeof(char));
    }
    
    long sum = cal(0,0,0,0);
    printf("%ld\n", sum);
    
    return 0;
}