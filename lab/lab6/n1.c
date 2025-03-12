#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int row, col, Q, R, B;
short **board;

int walkHV(int sr,int sc){
    // Check column
    for (int i = 0; i < row; ++i)
        if (i != sr && board[i][sc]) return 0;
    // Check row
    for (int j = 0; j < col; ++j)
        if (j != sc && board[sr][j]) return 0;
    
    return 1;
}

int walkO(int sr,int sc){

    for (int i = sr - 1, j = sc - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j]) return 0;
    // Check diagonal bottom-right (\)
    for (int i = sr + 1, j = sc + 1; i < row && j < col; ++i, ++j)
        if (board[i][j]) return 0;
    // Check diagonal top-right (/)
    for (int i = sr - 1, j = sc + 1; i >= 0 && j < col; --i, ++j)
        if (board[i][j]) return 0;
    // Check diagonal bottom-left (/)
    for (int i = sr + 1, j = sc - 1; i < row && j >= 0; ++i, --j)
        if (board[i][j]) return 0;

    return 1;
}

int queenWalk(int sr, int sc) {   
    return walkHV(sr,sc) && walkO(sr,sc);
}
int rookWalk(int sr,int sc){
    return walkHV(sr,sc);
}
int bishopWalk(int sr,int sc){
    return walkO(sr,sc);
}

long cal(int start, int q,int r,int b) {
    if(q == Q && r == R && b == B)return 1;
    else{
        long ways = 0;
        for(int index = start; index < row * col; index++) {
            int i = index / col, j = index % col;
                if(q < Q && !board[i][j] && queenWalk(i,j)) {
                    board[i][j] = 1;
                    ways += cal(index + 1, q + 1,r,b);
                    board[i][j] = 0;
                }
                if(r < R && !board[i][j] && rookWalk(i,j)) {
                    board[i][j] = 1;
                    ways += cal(index + 1, q,r + 1,b);
                    board[i][j] = 0;
                }
                if(b < B && !board[i][j] && bishopWalk(i,j)) {
                    board[i][j] = 1;
                    ways += cal(index + 1, q,r,b + 1);
                    board[i][j] = 0;
                }
    
        }
        return ways;

    }
    
}
// long bishop(int start, int b) {
//     if(b == B)return 1;
//     else{
//         long ways = 0;
//         for(int index = start; index < row * col; index++) {
//             int i = index / col, j = index % col;
//                 if(!board[i][j] && bishopWalk(i,j)) {
//                     board[i][j] = 1;
//                     ways += bishop(index + 1, b + 1);
//                     board[i][j] = 0;
//                 }
//         }
//         return ways;

//     }
    
// }
// long rook(int start, int r) {
//     if(r == R)return bishop(0,0);
//     else{
//         long ways = 0;
//         for(int index = start; index < row * col; index++) {
//             int i = index / col, j = index % col;
//                 if(!board[i][j] && rookWalk(i,j)) {
//                     board[i][j] = 1;
//                     ways += rook(index + 1, r + 1);
//                     board[i][j] = 0;
//                 }
//         }
//         return ways;

//     }
    
// }
// long queen(int start, int q) {
//     if(q == Q){
//         if(R) return rook(0,0);
//         else return bishop(0,0);
//     }
//     else{
//         long ways = 0;
//         for(int index = start; index < row * col; index++) {
//             int i = index / col, j = index % col;
//                 if(q < Q && !board[i][j] && queenWalk(i,j)) {
//                     board[i][j] = 1;
//                     ways += queen(index + 1, q + 1);
//                     board[i][j] = 0;
//                 }
//         }
//         return ways;

//     }
    
// }

int main() {
    scanf("%d %d", &row, &col);
    scanf("%d %d %d", &Q, &R, &B);
    
    board = (short**)malloc(row * sizeof(short*));
    for(int i = 0; i < row; i++) {
        board[i] = (short*)calloc(col, sizeof(short));
    }
    
    long sum = cal(0, 0,0,0);
    // long sum = queen(0,0);
    printf("%ld\n", sum);
    
    return 0;
}