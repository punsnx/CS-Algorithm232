#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int row, col, Q, R, B;
char **board;// 0 empty 1 queen 2 rook 3 bishop

int check(char *v, char *cQ, char *cR, char *cB) {
    if (*v && *v == *cQ) return 0;
    if (*v && *v == *cR) return 0;
    if (*v && *v == *cB) return 0;

    return 1;
}

int walkHV(char sr,char sc,char cQ,char cR,char cB){
    char v;// Check column
    for (char i = 0; i < row; ++i){
        v = board[i][sc];
        if(!check(&v,&cQ,&cR,&cB))return 0;

    }
    // Check row
    for (char j = 0; j < col; ++j){
        v = board[sr][j];
        if(!check(&v,&cQ,&cR,&cB))return 0;
    }
    
    return 1;
}

int walkO(char sr,char sc,char cQ,char cR,char cB){
    char v;
    // Check diagonal top-left (\)
    for (char i = sr - 1, j = sc - 1; i >= 0 && j >= 0; --i, --j){
        v = board[i][j];
        if(!check(&v,&cQ,&cR,&cB))return 0;
    }
    // Check diagonal bottom-right (\)
    for (char i = sr + 1, j = sc + 1; i < row && j < col; ++i, ++j){
        v = board[i][j];
        if(!check(&v,&cQ,&cR,&cB))return 0;
    }
    // Check diagonal top-right (/)
    for (char i = sr - 1, j = sc + 1; i >= 0 && j < col; --i, ++j){
        v = board[i][j];
        if(!check(&v,&cQ,&cR,&cB))return 0;
    }
    // Check diagonal bottom-left (/)
    for (char i = sr + 1, j = sc - 1; i < row && j >= 0; ++i, --j){
        v = board[i][j];
        if(!check(&v,&cQ,&cR,&cB))return 0;
    }

    return 1;
}

int queenWalk(char sr, char sc) {   
    return walkHV(sr,sc,1,2,0) && walkO(sr,sc,1,0,3);
}
int rookWalk(char sr,char sc){
    return walkHV(sr,sc,1,2,0) && walkO(sr,sc,1,0,3);
}
int bishopWalk(char sr,char sc){
    return walkHV(sr,sc,1,2,0) && walkO(sr,sc,1,0,3);
}

long cal(char start, char q,char r,char b) {
    if(q == Q && r == R && b == B)return 1;
    else{
        long ways = 0;
        for(char index = start; index < row * col; index++) {
            char i = index / col, j = index % col;
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
    
        }
        return ways;

    }
    
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